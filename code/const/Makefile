CXX=g++
GSL=$(HOME)/smToBsmLibs/gsl
SQUIDS=$(HOME)/smToBsmLibs/SQuIDS
IPATH=-I$(GSL)/include -I$(SQUIDS)/include
LPATH=-L$(GSL)/lib -L$(SQUIDS)/lib
CFLAGS=$(IPATH) -O2 -std=c++11
LFLAGS=$(LPATH) -lSQuIDS -lgsl -lgslcblas -lm

OBJ=obj/const.o
EXE=app/const.exe

all: $(EXE)

# folders
obj:
	mkdir obj

app:
	mkdir app

# compilation
obj/const.o: obj src/const.cpp
	$(CXX) -c $(CFLAGS) -o obj/const.o src/const.cpp

# linking
$(EXE): app $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(EXE)

# phony targets
run: $(EXE)
	./$(EXE)

clean:
	rm -rf obj app
