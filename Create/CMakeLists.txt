# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.2)
#项目名称, 参数值是 main, 该命令表示项目的名称是 main
project(main)
# 目标程序名
aux_source_directory(. DIR_TOOT_SRCS)
# 显示指定使用的C编译器 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
# 设置可执行文件目录，注意使用空格而不是花括号
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 指定生成目标，使用项目名称作为可执行文件名
add_executable(${PROJECT_NAME} ${DIR_TOOT_SRCS})
