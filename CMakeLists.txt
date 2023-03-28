cmake_minimum_required(VERSION 2.5)
project(MyMQ)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置调试信息 以及 启动C++11语言标准

# 定义参与编译的源代码文件 
aux_source_directory(net NET_SRC_LIST)
aux_source_directory(util UTIL_SRC_LIST)
aux_source_directory(. SRC_LIST)
aux_source_directory(cli CLI_SRC_LIST)
aux_source_directory(codec CODEC_SRC_LIST)
INCLUDE_DIRECTORIES(util  net codec)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC -pthread")
ADD_EXECUTABLE(demo ${SRC_LIST} ${NET_SRC_LIST} ${UTIL_SRC_LIST} ${CODEC_SRC_LIST})
ADD_EXECUTABLE(cli_demo ${CLI_SRC_LIST} ${CODEC_SRC_LIST})
