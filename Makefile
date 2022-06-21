.PHONY: all configure build run

all: configure build

run: build
	open ./build/TheSewerlands.app

configure:
	cmake -D CMAKE_BUILD_TYPE:STRING=Release -D CMAKE_C_COMPILER:FILEPATH=clang -D CMAKE_CXX_COMPILER:FILEPATH=clang++ -S . -B build -G "Ninja"

build:
	cmake --build build --config Release --target TheSewerlands --
