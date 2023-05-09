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
OBJ:=obj/main.o obj/vacuum.o
EXE:=app/main.exe

# data targets
DATA= # add data files here

all: $(EXE)

# folders
<<<<<<< HEAD
plots:
	mkdir plots

data: 
	mkdir data
||||||| 041ed6f
obj:
	mkdir obj
=======
data: 
	mkdir data

obj:
	mkdir obj
>>>>>>> sol

app:
	mkdir app

<<<<<<< HEAD
obj:
	mkdir obj
||||||| 041ed6f
# compilation
obj/vacuum.o: obj src/vacuum.cpp src/vacuum.hpp
	@$(CXX) -c $(CFLAGS) $(LFLAGS) -o obj/vacuum.o src/vacuum.cpp
=======
plots:
	mkdir plots

# compilation
obj/vacuum.o: obj src/vacuum.cpp src/vacuum.hpp
	@$(CXX) -c $(CFLAGS) $(LFLAGS) -o obj/vacuum.o src/vacuum.cpp
>>>>>>> sol

# data and plotting
plot: plots src/plot.py $(DATA)
	python3 src/plot.py

$(DATA): data $(EXE)
	./$(EXE)

# linking
$(EXE): app $(OBJ)
ifeq ($(SYS),Darwin)
	@mkdir -p lib
	@cp $(SQUIDS)/lib/libSQuIDS.dylib ./lib
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $(EXE) $(OBJ) $(LIBS)
else
	@$(CXX) $(CFLAGS) $(LDFLAGS) -o $(EXE) $(OBJ) $(LIBS)
endif

<<<<<<< HEAD
# compilation
obj/vacuum.o: obj src/vacuum.cpp src/vacuum.hpp
	@$(CXX) -c $(CFLAGS) $(LFLAGS) -o obj/vacuum.o src/vacuum.cpp

obj/main.o: obj src/main.cpp
	@$(CXX) -c $(CFLAGS) $(LFLAGS) -o obj/main.o src/main.cpp

||||||| 041ed6f
=======
# data and plotting
DATA=data/E.txt
DATA+=data/p_nu_e.txt
DATA+=data/p_nu_mu.txt
DATA+=data/p_nu_tau.txt

$(DATA): data $(EXE)
	./$(EXE)

plot: plots src/plot.py $(DATA)
	python3 src/plot.py

>>>>>>> sol
# phony targets
run: $(EXE) data
	./$(EXE)

clean:
<<<<<<< HEAD
	rm -rf plots data app lib obj
||||||| 041ed6f
	rm -rf obj app lib
=======
	rm -rf plots data obj app lib
>>>>>>> sol
