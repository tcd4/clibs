#!/bin/bash

echo "#####Building CLibs libraries.#####"

for d in src/*/
do
    name=${d}
    name=${name#src/}
    name=${name%/}

    echo "#####Building ${name} library.#####"

    cd ${d}src
    
    make
    make static

    cd ../../..
done
