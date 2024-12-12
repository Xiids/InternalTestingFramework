cmake_minimum_required(VERSION 3.11)
project(PerformanceTestcpp)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES_DIR1 "${PROJECT_SOURCE_DIR}/*.cxx")
file(GLOB SOURCES_DIR2 "${PROJECT_SOURCE_DIR}/../../src/vendorImpl/*.cxx")

set(SOURCES
    ${SOURCES_DIR1}
    ${SOURCES_DIR2}
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../../)



