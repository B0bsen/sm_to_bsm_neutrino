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

# remove all remaining junk directories
cd ~/
rm -rf $(find gsl-*/ | head -n 1)

