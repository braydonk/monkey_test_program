#!/bin/bash

# Copyright 2022 Google LLC.
# SPDX-License-Identifier: Apache-2.0

mkdir -p build
cd build
rm -rf *
cmake .. -DMK_LIB_ONLY=Yes -DMK_DEBUG=Yes -DMK_VALGRIND=Yes