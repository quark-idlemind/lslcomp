# lslcomp

Go package wrapping the Linden Lab / Sei Lisa LSL compiler.  Fork of
[github.com/Sei-Lisa/LSL-compiler](https://github.com/Sei-Lisa/LSL-compiler.git).

The package exposes two functions:

```go
// Parse syntax-checks an LSL script.  Returns nil if the script is clean,
// or an error containing all diagnostic lines
// ("(line, col) : ERROR : message").
func Parse(input string) error

// Compile compiles an LSL script to CIL (Mono/CLR) assembly text.
// className is used in the .assembly and .class directives; if empty,
// "script" is used (producing class name "LSL_script").
// Returns (cil, nil) on success or ("", err) on compile error.
func Compile(input, className string) (string, error)
```

## Regenerating the committed C++ sources

The repository commits the generated C++ files so that `go build` works
without any extra tools:

| Committed file | Generated from | Tool |
|---|---|---|
| `indra.l.cpp` | `indra.l` (via `indra.l.in`) | flex |
| `indra.y.cpp`, `indra.y.hpp` | `indra.y` | bison |
| `lscript_library.cpp` | `lscript_library.cpp.in` | kwdb |

If you change `indra.l.in`, `indra.y`, or `lscript_library.cpp.in`, regenerate
the committed files and commit the results.  You will need:

- [**kwdb**](https://bitbucket.org/Sei_Lisa/kwdb) with `indralex.py` copied
  into its `lsl2dfg/lsloutputs/` directory.  kwdb requires **Python 3**.
- **flex** (tested with 2.6)
- **bison** (tested with 2.3)

### Regenerating indra.l.cpp

`indra.l` is an intermediate file produced by kwdb from `indra.l.in`; it is
**not** committed (it is listed in `.gitignore`) because both its source
(`indra.l.in`) and its final output (`indra.l.cpp`) are committed.

```sh
# 1. Generate the intermediate indra.l from the template
python3 /path/to/kwdb/lsl2dfg/LSL2dfg.py \
    -y -d /path/to/kwdb/database/kwdb.xml \
    -g sl -f indralex \
    -i indra.l.in -o indra.l

# 2. Run flex to produce indra.l.cpp
flex -P indra_ -o indra.l.cpp indra.l

# 3. Commit the updated file
git add -f indra.l.cpp   # -f because indra.l.cpp is listed in .gitignore
git commit -m "Regenerate indra.l.cpp"
```

### Regenerating indra.y.cpp and indra.y.hpp

```sh
bison -p indra_ -d -o indra.y.cpp indra.y
git add -f indra.y.cpp indra.y.hpp
git commit -m "Regenerate indra.y.cpp / indra.y.hpp"
```

### Regenerating lscript_library.cpp

```sh
python3 /path/to/kwdb/lsl2dfg/LSL2dfg.py \
    -d /path/to/kwdb/database/kwdb.xml -g sl -f viewersrc \
    -i lscript_library.cpp.in \
| python3 /path/to/kwdb/lsl2dfg/LSL2dfg.py \
    -d /path/to/kwdb/database/kwdb.xml -f viewersrc -g os,-sl -t OSSL \
| python3 /path/to/kwdb/lsl2dfg/LSL2dfg.py \
    -d /path/to/kwdb/database/kwdb.xml -f viewersrc -g aa,-os,-sl -t AA \
    -o lscript_library.cpp
git add lscript_library.cpp
git commit -m "Regenerate lscript_library.cpp"
```

## License

Licensed under the GNU LGPL v2.1, like the viewer sources it is based on.

Copyright © 2010 Linden Research, Inc.  
Copyright © 2017 Sei Lisa.
