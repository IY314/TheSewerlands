all: configure build

run: build
    ./build/TheSewerlands

configure:
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build -G Ninja

build: configure
    cmake --build build --config Release --target TheSewerlands --
