# variables
## Directories
LIBDIR:=lib
INCDIR:=include
SQINCDIR:=include/SQuIDS
SRCDIR:=src
INSTALL_LIBDIR:=lib
PATH_SQUIDS:=$(HOME)/Libraries/SQuIDS

## Compiler
CC:=gcc
CXX:=g++
AR:=ar
LD:=g++

## Flags
### Compiler
GSL_CFLAGS=-I$(HOME)/Libraries/gsl/2.7.1/include

CFLAGS:= -O3 -fPIC -I$(INCDIR) $(GSL_CFLAGS)

CXXFLAGS:= -std=c++11
CXXFLAGS+=-I$(PATH_SQUIDS)/$(INCDIR)

### Linker
GSL_LDFLAGS=-L$(HOME)/Libraries/gsl/2.7.1/lib -lgsl -lgslcblas -lm

LDFLAGS:= -Wl,-rpath -Wl,$(LIBDIR) $(GSL_LDFLAGS)
LDFLAGS+= -Wl,-rpath -Wl,$(PATH_SQUIDS)/$(LIBDIR) -L$(PATH_SQUIDS)/$(LIBDIR) -lSQuIDS $(GSL_LDFLAGS)

## main target name
EXE=app/vacuum.exe

# Compilation rules
all: $(EXE) data

obj/vacuum.o: obj src/vacuum.cpp src/vacuum.h
	$(CXX) -c $(CXXFLAGS) $(CFLAGS) -o obj/vacuum.o src/vacuum.cpp

obj/main.o: obj src/main.cpp src/vacuum.h
	$(CXX) -c $(CXXFLAGS) $(CFLAGS) -o obj/main.o src/main.cpp

$(EXE): app obj/main.o obj/vacuum.o
	$(CXX) $(CXXFLAGS) $(CFLAGS) obj/main.o obj/vacuum.o $(LDFLAGS)  -o $(EXE)

data:
	mkdir data

obj:
	mkdir obj

exe:
	$(EXE)

app:
	mkdir app

clean:
	rm -rf app obj

.PHONY: clean exe

