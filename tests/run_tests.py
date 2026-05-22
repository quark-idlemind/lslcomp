#!/usr/bin/env python3
"""Test harness for the LSL syntax checker.

Each .lsl file in this directory must carry an EXPECT directive on its
very first line (before any code).  Supported forms:

    // EXPECT ERROR: <message text>
    // EXPECT WARNING: <message text>
    // EXPECT CLEAN

The compiler writes diagnostics to stderr in the format:
    (line, col) : ERROR : <message text>
    (line, col) : WARNING : <message text>

The harness runs the compiler on each script, then:
  ERROR   - passes if any stderr line contains "ERROR : <message text>"
  WARNING - passes if any stderr line contains "WARNING : <message text>"
  CLEAN   - passes if stderr contains no "ERROR :" or "WARNING :" lines

Usage:
    python3 tests/run_tests.py [path/to/lslcomp]

If the compiler path is not given it defaults to ./lslcomp (relative to
the project root, i.e. one directory above this script).
"""

import os
import re
import shutil
import subprocess
import sys
import tempfile


# ---------------------------------------------------------------------------
# Locate compiler

def default_compiler():
    """Return the default path to the lslcomp binary."""
    here = os.path.dirname(os.path.abspath(__file__))
    root = os.path.dirname(here)
    return os.path.join(root, "lslcomp")


# ---------------------------------------------------------------------------
# Parse the EXPECT directive

_EXPECT_RE = re.compile(
    r'^//\s*EXPECT\s+(ERROR|WARNING)\s*:\s*(.*)', re.IGNORECASE)
_CLEAN_RE = re.compile(r'^//\s*EXPECT\s+CLEAN', re.IGNORECASE)


def parse_expect(path):
    """Return (kind, text) where kind is 'ERROR', 'WARNING', or 'CLEAN'.

    text is the expected message substring for ERROR/WARNING, or None for
    CLEAN.  Returns (None, None) if the directive is missing or malformed.
    """
    with open(path, encoding="utf-8") as fh:
        first = fh.readline().rstrip("\n")

    m = _EXPECT_RE.match(first)
    if m:
        return m.group(1).upper(), m.group(2).strip()

    if _CLEAN_RE.match(first):
        return "CLEAN", None

    return None, None


# ---------------------------------------------------------------------------
# Run one test

def run_test(compiler, src_path):
    """Run the compiler on src_path and check against the EXPECT directive.

    Returns (passed: bool, detail: str).
    """
    kind, text = parse_expect(src_path)
    if kind is None:
        return False, "No EXPECT directive found on the first line"

    # Run the compiler in a temporary directory so it does not litter the
    # source tree with .out and .cil files.
    with tempfile.TemporaryDirectory() as tmpdir:
        dst = os.path.join(tmpdir, os.path.basename(src_path))
        shutil.copy(src_path, dst)
        try:
            proc = subprocess.run(
                [compiler, dst],
                capture_output=True,
                text=True,
            )
        except FileNotFoundError:
            return False, "Compiler not found: " + compiler

        stderr = proc.stderr

    lines = stderr.splitlines()

    exit_code = proc.returncode

    if kind == "CLEAN":
        bad = [l for l in lines if " : ERROR : " in l or " : WARNING : " in l]
        if bad:
            snippet = "\n    ".join(bad)
            return False, "Expected no diagnostics but got:\n    " + snippet
        if exit_code != 0:
            return False, f"Expected exit 0 for clean script but got exit {exit_code}"
        return True, "no diagnostics, exit 0"

    # ERROR: compiler must report the message AND exit non-zero.
    # WARNING: compiler must report the message AND exit zero (warnings don't fail).
    needle = kind + " : " + text
    hits = [l for l in lines if needle in l]

    if kind == "ERROR":
        if not hits:
            diag_lines = [l for l in lines if " : ERROR : " in l or " : WARNING : " in l]
            if diag_lines:
                got = "\n    ".join(diag_lines)
                return False, (
                    'Expected "' + needle + '"\n'
                    "    but got:\n    " + got
                )
            return False, (
                'Expected "' + needle + '"\n'
                "    but stderr was empty (compiler produced no diagnostics)"
            )
        if exit_code == 0:
            return False, f'Got expected error message but exit code was 0 (want non-zero)'
        return True, hits[0].strip()

    # WARNING
    if not hits:
        diag_lines = [l for l in lines if " : ERROR : " in l or " : WARNING : " in l]
        if diag_lines:
            got = "\n    ".join(diag_lines)
            return False, (
                'Expected "' + needle + '"\n'
                "    but got:\n    " + got
            )
        return False, (
            'Expected "' + needle + '"\n'
            "    but stderr was empty (compiler produced no diagnostics)"
        )
    if exit_code != 0:
        return False, f'Got expected warning message but exit code was {exit_code} (want 0)'
    return True, hits[0].strip()


# ---------------------------------------------------------------------------
# Main

def main():
    if len(sys.argv) > 1:
        compiler = os.path.abspath(sys.argv[1])
    else:
        compiler = default_compiler()

    if not os.path.isfile(compiler):
        print("ERROR: compiler binary not found:", compiler)
        print("Build the project first, or pass the path as an argument.")
        sys.exit(2)

    tests_dir = os.path.dirname(os.path.abspath(__file__))
    lsl_files = sorted(
        f for f in os.listdir(tests_dir) if f.endswith(".lsl")
    )

    if not lsl_files:
        print("No .lsl test files found in", tests_dir)
        sys.exit(1)

    col_w = max(len(f) for f in lsl_files)
    passed = failed = 0

    for name in lsl_files:
        ok, detail = run_test(compiler, os.path.join(tests_dir, name))
        tag = "PASS" if ok else "FAIL"
        print(f"{tag}  {name:<{col_w}}  {detail.splitlines()[0]}")
        if not ok:
            for extra in detail.splitlines()[1:]:
                print(" " * (6 + col_w) + extra)
        if ok:
            passed += 1
        else:
            failed += 1

    total = passed + failed
    print()
    print(f"{passed}/{total} passed", end="")
    if failed:
        print(f"  ({failed} FAILED)")
        sys.exit(1)
    else:
        print()
        sys.exit(0)


if __name__ == "__main__":
    main()
