CXX=g++
CPPFLAGS=-DLINUX=1 -Illcommon -Ilscript
CFLAGS=-g -O0 -Wall -Wextra -Wunused-function
LDFLAGS=

LSLK=~/apps/secondlife/scripts/lslkeywords/

all : lslcomp

indra.l : indra.l.in
	$(LSLK)lsl2dfg/LSL2dfg.py -y -d $(LSLK)database/kwdb.xml -g sl -f indralex -i $< -o $@

lscript_library/lscript_library.cpp : lscript_library/lscript_library.cpp.in
	\
   $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -g sl -f viewersrc -i $<\
 | $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -f viewersrc -g os,-sl -t OSSL\
 | $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -f viewersrc -g aa,-os,-sl -t AA -o $@


indra.l.cpp : indra.l
	flex -P indra_ -o indra.l.cpp indra.l

indra.y.cpp indra.y.hpp : indra.y
	bison -p indra_ -d -o indra.y.cpp indra.y


%.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) "$<" -o "$@"

# Known problem: there are more unlisted dependencies than these,
# mainly lots of .h files, but we're not analyzing them. Make clean if
# in doubt.
lscript_library/lscript_library.o : lscript_library/lscript_library.cpp
lslcomp.o : lslcomp.cpp
lscript_error.o : lscript_error.cpp
lscript_scope.o : lscript_scope.cpp
lscript_tree.o : lscript_tree.cpp lscript_tree.h llcommon/llstring.h
lscript_typecheck.o : lscript_typecheck.cpp
indra.l.o : indra.l.cpp indra.y.hpp
indra.y.o : indra.y.cpp indra.y.hpp
llcommon/llfile.o : llcommon/llfile.cpp
llcommon/llstringtable.o : llcommon/llstringtable.cpp

COMPILER_OBJS = indra.l.o indra.y.o\
 lscript_library/lscript_library.o\
 lscript_error.o\
 lscript_scope.o lscript_tree.o\
 lscript_typecheck.o\
 llcommon/llfile.o llcommon/llstringtable.o

lslcomp : lslcomp.o $(COMPILER_OBJS)
	g++ $(CFLAGS) $(LDFLAGS) lslcomp.o $(COMPILER_OBJS) -o lslcomp

tests/test_leak.o : tests/test_leak.cpp indra.l.hpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I. tests/test_leak.cpp -o tests/test_leak.o

test_leak : tests/test_leak.o $(COMPILER_OBJS)
	g++ $(CFLAGS) $(LDFLAGS) tests/test_leak.o $(COMPILER_OBJS) -o test_leak


clean :
	rm -f lslcomp test_leak *.o tests/test_leak.o\
 lscript_library/*.o llcommon/*.o\
 indra.l.cpp indra.l indra.y.cpp indra.y.hpp\
 lscript_library/lscript_library.cpp

.PHONY : all clean test_leak
