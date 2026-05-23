#!/usr/bin/env python3
"""Memory-leak stress test runner for lscript_compile().

Builds tests/test_leak.cpp, runs it 100 x 3 = 300 compilations for
correctness, then re-runs it under a memory checker:
  - macOS: 'leaks --atExit'
  - Linux: 'valgrind --leak-check=full'
  - fallback: reports that leak checking was skipped.

Usage:
    python3 tests/run_leak_test.py [path/to/kwdb/]
"""

import os
import platform
import shutil
import subprocess
import sys


def find_lslk():
    candidates = [
        os.path.expanduser("~/src/LSL-compiler/kwdb/"),
        os.path.expanduser("~/apps/secondlife/scripts/lslkeywords/"),
    ]
    for c in candidates:
        if os.path.isdir(c):
            return c
    return candidates[0]


def build(root, lslk):
    print("Building test_leak ...")
    r = subprocess.run(
        ["make", f"LSLK={lslk}", "test_leak"],
        cwd=root,
        capture_output=True,
        text=True,
    )
    if r.returncode != 0:
        tail = r.stderr[-3000:] if len(r.stderr) > 3000 else r.stderr
        print("Build FAILED:\n" + tail)
        sys.exit(1)
    print("Build OK\n")


def run_correctness(binary, root):
    print("Correctness check: 100 iterations x 3 scripts = 300 compilations ...")
    r = subprocess.run(
        [binary],
        cwd=root,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,  # suppress per-compile diagnostic output
        text=True,
    )
    print(r.stdout.strip())
    if r.returncode != 0:
        print("FAIL: unexpected results (see above)")
        sys.exit(1)
    print()


def run_leaks_macos(binary, root):
    if not shutil.which("leaks"):
        return False
    print("Leak check (macOS 'leaks --atExit') ...")
    r = subprocess.run(
        ["leaks", "--atExit", "--", binary],
        cwd=root,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    output = r.stdout.strip()
    # Print the summary lines from leaks
    for line in output.splitlines():
        if any(kw in line for kw in ("leak", "LEAK", "malloc", "Process", "node")):
            print(line)
    print()
    if "0 leaks for 0 total leaked bytes" in output:
        print("PASS: no leaks detected")
        return True
    if "leaks for" in output:
        print("FAIL: leaks detected -- full leaks output above")
        sys.exit(1)
    # leaks may be blocked by SIP or entitlements on newer macOS
    print("NOTE: 'leaks' produced unexpected output; check manually.")
    print("      (On macOS 12+ you may need to disable SIP or use Instruments.)")
    return True


def run_valgrind(binary, root):
    if not shutil.which("valgrind"):
        return False
    print("Leak check (valgrind --leak-check=full) ...")
    r = subprocess.run(
        [
            "valgrind",
            "--leak-check=full",
            "--show-leak-kinds=definite,indirect",
            "--error-exitcode=1",
            binary,
        ],
        cwd=root,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.PIPE,
        text=True,
    )
    # valgrind summary goes to stderr
    summary = [
        l for l in r.stderr.splitlines()
        if any(kw in l for kw in (
            "ERROR SUMMARY", "LEAK SUMMARY",
            "definitely lost", "indirectly lost", "still reachable",
        ))
    ]
    for l in summary:
        print(l)
    print()
    if r.returncode == 0:
        print("PASS: no definite leaks detected by valgrind")
    else:
        print("FAIL: valgrind detected leaks or errors")
        sys.exit(1)
    return True


def main():
    lslk = sys.argv[1] if len(sys.argv) > 1 else find_lslk()
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    binary = os.path.join(root, "test_leak")

    build(root, lslk)
    run_correctness(binary, root)

    if platform.system() == "Darwin":
        if not run_leaks_macos(binary, root):
            run_valgrind(binary, root) or print(
                "NOTE: no leak checker found (install Xcode command-line tools"
                " for 'leaks', or valgrind).\n"
                "      Correctness check passed; leak check skipped."
            )
    else:
        if not run_valgrind(binary, root):
            print(
                "NOTE: valgrind not found.\n"
                "      Correctness check passed; leak check skipped."
            )


if __name__ == "__main__":
    main()
