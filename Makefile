.PHONY: all configure build run

all: configure build

run: build
	open ./build/TheSewerlands.app

configure:
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S. -Bbuild -G "Ninja"

build:
	cmake --build build --config Release --target TheSewerlands --
