cmake_minimum_required(VERSION 4.0)
project(culm-runtime)

file(GLOB_RECURSE sources src/*.c src/*.h)

add_executable(culm-runtime ${sources})
