# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(MyProject)

# 设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 包含每个目标的子目录
add_subdirectory(source/main)
add_subdirectory(source/esp_main)
add_subdirectory(source/ngrok_main)

# 在当前目录下创建 bin 目录的软链接
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/bin ${CMAKE_BINARY_DIR}/bin)
