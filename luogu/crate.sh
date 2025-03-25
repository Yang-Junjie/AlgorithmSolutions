#!/bin/bash
if [ -z "$1" ];then
    echo "please give dir a name!"
    exit 1
fi

TARGET_DIR=$1

mkdir -p "$TARGET_DIR"

cat <<EOL>"$TARGET_DIR/main.cpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    return 0;
}
EOL

cat <<EOL>"$TARGET_DIR/CMakeLists.txt"
cmake_minimum_required(VERSION 3.10.0)
project(Test)
add_executable(a main.cpp)
EOL

mkdir -p "$TARGET_DIR/build"

echo "crate dir successful!"

cd "./$TARGET_DIR"
