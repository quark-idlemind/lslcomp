CXX=g++
CPPFLAGS=-DLINUX=1 -Iparse -Iparse/llcommon -Iparse/lscript
CFLAGS=-g -O0 -Wall -Wextra -Wunused-function
LDFLAGS=

LSLK=~/apps/secondlife/scripts/lslkeywords/

all : lslcomp

# ---- Code generation -------------------------------------------------
# The generated files (indra.l.cpp, indra.y.cpp, indra.y.hpp,
# lscript_library.cpp) are committed to parse/ so that 'go build' works
# without requiring kwdb, flex, or bison.  Re-run 'make generate' only
# when the templates change, then commit the new generated files.

parse/indra.l : parse/indra.l.in
	$(LSLK)lsl2dfg/LSL2dfg.py -y -d $(LSLK)database/kwdb.xml -g sl \
	  -f indralex -i $< -o $@

parse/lscript_library.cpp : parse/lscript_library.cpp.in
	$(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -g sl \
	  -f viewersrc -i $< \
	| $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml \
	  -f viewersrc -g os,-sl -t OSSL \
	| $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml \
	  -f viewersrc -g aa,-os,-sl -t AA -o $@

parse/indra.l.cpp : parse/indra.l
	flex -P indra_ -o $@ $<

parse/indra.y.cpp parse/indra.y.hpp : parse/indra.y
	bison -p indra_ -d -o parse/indra.y.cpp parse/indra.y

generate : parse/indra.l.cpp parse/indra.y.cpp parse/indra.y.hpp \
           parse/lscript_library.cpp

# ---- Compilation rules -----------------------------------------------

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) "$<" -o "$@"

parse/lscript_library.o  : parse/lscript_library.cpp
lslcomp.o                : lslcomp.cpp parse/indra.l.hpp
parse/lscript_error.o    : parse/lscript_error.cpp
parse/lscript_scope.o    : parse/lscript_scope.cpp
parse/lscript_tree.o     : parse/lscript_tree.cpp parse/lscript_tree.h \
                            parse/llcommon/llstring.h
parse/lscript_typecheck.o: parse/lscript_typecheck.cpp
parse/indra.l.o          : parse/indra.l.cpp parse/indra.y.hpp
parse/indra.y.o          : parse/indra.y.cpp parse/indra.y.hpp
parse/llfile.o           : parse/llfile.cpp
parse/llstringtable.o    : parse/llstringtable.cpp

COMPILER_OBJS = \
  parse/indra.l.o \
  parse/indra.y.o \
  parse/lscript_library.o \
  parse/lscript_error.o \
  parse/lscript_scope.o \
  parse/lscript_tree.o \
  parse/lscript_typecheck.o \
  parse/llfile.o \
  parse/llstringtable.o

# ---- Binaries --------------------------------------------------------

lslcomp : lslcomp.o $(COMPILER_OBJS)
	g++ $(CFLAGS) $(LDFLAGS) lslcomp.o $(COMPILER_OBJS) -o lslcomp

tests/test_leak.o : tests/test_leak.cpp parse/indra.l.hpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) tests/test_leak.cpp \
	  -o tests/test_leak.o

test_leak : tests/test_leak.o $(COMPILER_OBJS)
	g++ $(CFLAGS) $(LDFLAGS) tests/test_leak.o $(COMPILER_OBJS) \
	  -o test_leak

# ---- Maintenance -----------------------------------------------------

clean :
	rm -f lslcomp test_leak *.o parse/*.o tests/test_leak.o

.PHONY : all clean generate test_leak
