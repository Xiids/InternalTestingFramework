cmake_minimum_required(VERSION 3.10)
project(PerformanceTestcpp)

set(CMAKE_CXX_STANDARD 14)

# 查找指定目录中的 .cxx 文件
file(GLOB SOURCES_DIR1 "src/*.cxx")

set(SOURCES
    ${SOURCES_DIR1}
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/)



