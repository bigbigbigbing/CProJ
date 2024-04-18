# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.0)

function(find_and_link_library TARGET LIBRARY)
    find_library(LIBRARY_PATH ${LIBRARY})
    if(LIBRARY_PATH)
        target_link_libraries(${TARGET} ${LIBRARY_PATH})
    else()
        message(FATAL_ERROR "${LIBRARY} not found")
    endif()
endfunction()

# 设置项目名称
project(MyProject)
set(MY_TARGET main)

# 添加可执行文件，并指定源文件
add_executable(${MY_TARGET} src/main.c)

# 添加包含路径，以便编译器能够找到头文件
target_include_directories(${MY_TARGET} PUBLIC include)

# 设置生成 map 文件的选项
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${CMAKE_BINARY_DIR}/${MY_TARGET}.map")

# 在生成期间去除符号表
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--strip-all")

# 设置动态库所在目录
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 查找 libjson-c.so.5.1.0 动态库
find_and_link_library(${MY_TARGET} json-c)
