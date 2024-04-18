# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(MyProject)

# 添加可执行文件，并指定源文件
add_executable(ngrok src/main.c)

# 添加包含路径，以便编译器能够找到头文件
target_include_directories(ngrok PUBLIC include)


