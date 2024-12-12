TOOLCHAIN=$PWD/cmake/zig-toolchain.cmake

mkdir -p .zig
pushd .zig
cmake .. -DCMAKE_BUILD_TYPE=Release -DSTRIPPED=ON -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN
make -j8
popd
