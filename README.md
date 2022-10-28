# monkey_test_program

Simple starter program that links the monkey-static-core library and runs an empty server with it. Mainly used to valgrind and test specific behaviours for monkey library changes.

# Requirements 
* CMake 3.0+
* C compiler (only tested with `gcc` at the moment)

# Usage

Start by cloning the repo with submodules:
```bash
git clone --recurse-submodules https://github.com/braydonk/monkey_test_program.git
```

You can sub in your own fork/commit of `monkey` by updating the `.gitmodules` folder and running `git submodule update`, then checking out the desired commit.

To build the project, do the following:

```bash
bash configure.sh
cd build
cmake --build .
```

This builds a binary in `build` called `mk`.