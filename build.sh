mkdir build
mkdir -p build/protos
cd build
export CXX=/usr/bin/clang++
cmake ..
make
