# TheSewerlands
A procedurally generated 2D dungeoneering game.

## Installation
TheSewerlands is macOS only (for now).

CMake >= 3.23 is required:
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
cmake -S . -B ./build -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ --no-warn-unused-cli -G "Unix Makefiles"
cmake --build --config Release --target all -j 10 --
```
