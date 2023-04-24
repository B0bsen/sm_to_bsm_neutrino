CXX=g++
GSL=$(HOME)/smToBsmLibs/gsl
SQUIDS=$(HOME)/smToBsmLibs/SQuIDS
IPATH=-I$(GSL)/include -I$(SQUIDS)/include
LPATH=-L$(GSL)/lib -L$(SQUIDS)/lib
CFLAGS=$(IPATH) -O2 -std=c++11
LFLAGS=$(LPATH) -lSQuIDS -lgsl -lgslcblas -lm

OBJ=obj/SU_vector.o
EXE=app/SU_vector.exe

all: $(EXE)

# folders
obj:
	mkdir obj

app:
	mkdir app

# compilation
obj/SU_vector.o: obj src/SU_vector.cpp
	$(CXX) -c $(CFLAGS) -o obj/SU_vector.o src/SU_vector.cpp

# linking
$(EXE): app $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(EXE)

# phony targets
run: $(EXE)
	./$(EXE)

clean:
	rm -rf obj app
