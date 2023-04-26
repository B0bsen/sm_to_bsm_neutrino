# system type
SYS:=$(shell uname)

# c++ compiler
CXX:=g++

# define variables for GSL and SQuIDS paths
GSL:=$(HOME)/smToBsmLibs/gsl
SQUIDS:=$(HOME)/smToBsmLibs/SQuIDS

# specify include and library paths
IPATH:=-I$(GSL)/include -I$(SQUIDS)/include
LPATH:=-L$(GSL)/lib -L$(SQUIDS)/lib

# compiler and linker options
CFLAGS:=$(IPATH) -O2 -std=c++11
LDFLAGS:=$(LPATH)

# additional libraries
LIBS:=-lSQuIDS -lgsl -lgslcblas -lm

# define object files and executable
OBJ:=obj/SU_vector.o
EXE:=app/SU_vector.exe

all: $(EXE)

# folders
obj:
	mkdir obj

app:
	mkdir app

# compilation
obj/SU_vector.o: obj src/SU_vector.cpp
	@$(CXX) -c $(CFLAGS) $(LFLAGS) -o obj/SU_vector.o src/SU_vector.cpp

# linking
$(EXE): app $(OBJ)
ifeq ($(SYS),Darwin)
	@mkdir -p lib
	@cp $(SQUIDS)/lib/libSQuIDS.dylib ./lib
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $(EXE) $(OBJ) $(LIBS)
else
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $(EXE) $(OBJ) $(LIBS)
endif

# phony targets
run: $(EXE)
	./$(EXE)

clean:
	rm -rf obj app lib
