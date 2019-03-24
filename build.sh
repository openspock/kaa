mkdir -p build/kaasvc/protos
cd build
export CXX=/usr/bin/clang++
cmake ..
make
