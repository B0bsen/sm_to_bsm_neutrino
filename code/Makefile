# variables
## global
OS := $(shell uname)
OBJ := obj/main.o

## macOS specific
MAC_CFLAGS := -Ofast -std=c++11
MAC_LFLAGS := -lgsl -lgslcblas

## linux specific
LX_IPATH := -I/home/dhellmann/Libraries/gsl/include
LX_LPATH := -L/home/dhellmann/Libraries/gsl/lib
LX_LIBS := -lgsl -lgslcblas -lm
LX_CFLAGS := -pthread -Ofast -std=c++11
LX_LFLAGS := -pthread -fno-builtin $(LX_LIBS)

# linking
app/main: app $(OBJ)
ifeq ($(OS),Darwin)
	@echo Linking...
	@g++ -o app/main $(OBJ) $(MAC_LFLAGS)
else ifeq ($(OS),Linux)
	@echo Linking...
	@g++ $(LX_LPATH) -o app/main $(OBJ) $(LX_LFLAGS)
endif

# compilation
obj/main.o: obj src/main.cpp
ifeq ($(OS), Darwin)
	@echo Compiling...
	@g++ -c -o obj/main.o src/main.cpp $(MAC_CFLAGS)
else ifeq ($(OS),Linux)
	@echo Compiling...
	@g++ $(LX_IPATH) -c -o obj/main.o src/main.cpp $(LX_CFLAGS)
endif

# necessary folders
app:
	@mkdir app

obj:
	@mkdir obj

# phony targets
exe: app/main
	@./app/main

clean:
	@echo Deleting reproducable files...
	@rm -rf app obj

.PHNOY: exe clean