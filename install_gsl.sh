#!/bin/bash
# go to homefolder and create library directory
cd ~/
mkdir -p smToBsmLibs/gsl

# download gsl
wget ftp://ftp.gnu.org/gnu/gsl/gsl-latest.tar.gz

# unpack and configure the library
tar -zxvf gsl-latest.tar.gz
rm gsl-latest.tar.gz
cd $(find gsl-*/ | head -n 1)
./configure --prefix=$HOME/smToBsmLibs/gsl

# make, check and install
make
make check
make install

# necessary under linux
LD_LIBRARY_PATH=$HOME/smToBsmLibs/gsl/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

# remove all remaining junk directories
cd ~/
rm -rf $(find gsl-*/ | head -n 1)

