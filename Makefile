.PHONY: all configure build

all: configure build

configure:
	cmake -D CMAKE_BUILD_TYPE:STRING=Release -D CMAKE_C_COMPILER:FILEPATH=clang -D CMAKE_CXX_COMPILER:FILEPATH=clang++ -S . -B build -G "Ninja"

build:
	cmake --build build --config Release --target TheSewerlands --
