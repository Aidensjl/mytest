cmake_minimum_required(VERSION 2.8)

project(mytask)

# 检查构建类型
if(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Release)
endif()
MESSAGE("build type is " ${CMAKE_BUILD_TYPE})

# 设置编译标志
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall   -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")

# 设置添加调试信息，不然在cmake .. -DCMAKE_BUILD_TYPE=debug设置，否则断点无效
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# 检查C++11或C++0x支持
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#  添加预定义的宏 -D COMPILEDWITHC11
   add_definitions(-DCOMPILEDWITHC11)
   message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
   add_definitions(-DCOMPILEDWITHC0X)
   message(STATUS "Using flag -std=c++0x.")
else()
   message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# 添加自定义的CMake模块，后续采用find_package()可以在这个路径下查找
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)


# 查找文件
find_package(OpenCV 3.4.5 REQUIRED)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV > 4.4 not found.")
endif()

MESSAGE("OPENCV VERSION:${OpenCV_VERSION}")

# 包含的头文件路径
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    
)

# 设置输出lib库路径，下面是最新用法，类似之前的LIBRARY_OUTPUT_PATH
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 设置输出可执行文件的路径，下面是最新用法，类似之前的LIBRARY_OUTPUT_PATH
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 添加子文件夹，当下cmakelists.txt文件下的设置会影响子文件夹中的设置
add_subdirectory(src)


# 生成可执行程序
add_executable(myapp
   test/main.cpp
)

# 链接可执行程序
# 当你使用 target_link_libraries(my_executable ${OpenCV_LIBS}) 时，
# CMake 会自动将 ${OpenCV_INCLUDE_DIRS} 中的路径添加到编译过程中
# 使得你在源代码中可以直接使用OpenCV的头文件
# 无需手动指定路径使用 include_directories(${OpenCV_INCLUDE_DIRS}) 进行设置。
# target_link_libraries(myapp ${PROJECT_SOURCE_DIR}/lib/libmyfunc.so)
target_link_libraries(myapp myfunc ${OpenCV_LIBS})

