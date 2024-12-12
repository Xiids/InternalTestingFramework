cmake_minimum_required(VERSION 3.11)
project(PerformanceTestcpp)

# 强制使用 C++14 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找源文件
file(GLOB SOURCES_DIR1 "${PROJECT_SOURCE_DIR}/*.cxx")
file(GLOB SOURCES_DIR2 "${PROJECT_SOURCE_DIR}/../../src/vendorImpl/*.cxx")

set(SOURCES
    ${SOURCES_DIR1}
    ${SOURCES_DIR2}
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 包含头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../../)

# 查找 RTIConnextDDS 包
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake/rti")
find_package(RTIConnextDDS REQUIRED)

# 配置 RTIConnextDDS 如果找到
if(RTIConnextDDS_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${CONNEXTDDS_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${RTIConnextDDS_LIBRARIES})
    message(STATUS "RTIConnextDDS Include Directories: ${RTIConnextDDS_INCLUDE_DIRS}")

else()
    message(FATAL_ERROR "RTIConnextDDS not found!")
endif()
