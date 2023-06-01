cmake_minimum_required(VERSION 3.0)

project(speech)

include_directories(${CMAKE_SOURCE_DIR}/include)


# "GLOB"自动添加该目录下的源文件放入"ALL_SOURCE"
file(GLOB ALL_SOURCE "*.cpp")

# "GLOB_RECURSE"自动添加该目录下以及子目录下的源文件放入"ALL_SOURCE"
# file(GLOB_RECURSE ALL_SOURCE "*.cpp" "*.c")

add_executable(main ${ALL_SOURCE})
