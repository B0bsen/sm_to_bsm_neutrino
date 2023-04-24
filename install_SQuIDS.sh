#!/bin/bash

# make folder for SQuIDS
cd ~/
mkdir -p smToBsmLibs/SQuIDS

# download SQuIDS
git clone https://github.com/jsalvado/SQuIDS.git

# configure SQuIDS
cd $(find SQuIDS* | head -n 1)
./configure --with-gsl-incdir=$HOME/smToBsmLibs/gsl/include --with-gsl-libdir=$HOME/smToBsmLibs/gsl/lib --prefix=$HOME/smToBsmLibs/SQuIDS

# make, test and install
make
make test
make install

# remove junk folders
cd ~/
rm -rf $(find SQuIDS* | head -n 1)
