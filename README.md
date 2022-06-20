# TheSewerlands
A procedurally generated 2D dungeoneering game set in a fictional maze of sewers much like those of Paris.

## Installation
TheSewerlands is macOS only (for now).

[CMake](https://cmake.org/download/) >= 3.23 is required.

Using [Homebrew](https://brew.sh/) to install CMake:
```sh
brew install cmake
```

Clone the repository:
```sh
git clone --recurse-submodules https://github.com/IY314/TheSewerlands.git
```

Build:
```sh
# Only tested on these options, so modify them at your own risk!
cmake -S . -B ./build -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ --no-warn-unused-cli -G "Ninja"
cmake --build --config Release --target all -j 10 --
```
