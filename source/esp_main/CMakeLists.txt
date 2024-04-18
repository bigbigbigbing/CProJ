# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(MyProject)

# 添加可执行文件，并指定源文件
add_executable(esp src/main.c)

# 添加包含路径，以便编译器能够找到头文件
target_include_directories(esp PUBLIC include)

# 设置生成 map 文件的选项
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${CMAKE_BINARY_DIR}/main.map")

# 在生成期间去除符号表
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--strip-all")
