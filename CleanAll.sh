#!/bin/bash

echo "#####Cleaning CLibs libraries.#####"

for d in src/*/
do
    name=${d}
    name=${name#src/}
    name=${name%/}

    echo "#####Cleaning ${name} library.#####"

    cd ${d}src
   
    make clean

    cd ../../..
done
