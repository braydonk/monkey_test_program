#!/bin/bash

mkdir -p build
cd build
rm -rf *
cmake .. -DMK_LIB_ONLY=Yes -DMK_DEBUG=Yes -DMK_VALGRIND=Yes