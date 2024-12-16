cmake_minimum_required(VERSION 3.11)
project(PerformanceTestcpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(DEFINED ENV{NDDSHOME})
    set(NDDSHOME_PATH $ENV{NDDSHOME})
    message(STATUS "NDDSHOME is set to: ${NDDSHOME_PATH}")
else()
    message(FATAL_ERROR "NDDSHOME is not set!")
endif()

link_directories($ENV{NDDSHOME}/lib/${CONNEXTDDS_ARCH})

#TODO using rti cmake fun

set(SOURCES
    ${PROJECT_SOURCE_DIR}/communicationManager_test_main.cxx
    ${PROJECT_SOURCE_DIR}/../../src/vendorImpl/rti/rtiDdsImpl.cxx
    ${PROJECT_SOURCE_DIR}/../../srcData/rti/test.cxx
    ${PROJECT_SOURCE_DIR}/../../srcData/rti/testPlugin.cxx
)



add_definitions(-DRTI_LINUX -DRTI_UNIX -Dm64)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE $ENV{NDDSHOME}/include 
                                                   $ENV{NDDSHOME}/include/ndds 
                                                   $ENV{NDDSHOME}/include/ndds/hpp
                                                   ${PROJECT_SOURCE_DIR}/../../
                                                   ${PROJECT_SOURCE_DIR}/../../srcData/rti/)
target_link_libraries(${PROJECT_NAME} 
                        nddscpp2  
                        nddsc 
                        nddscore 
)

# message(STATUS "target_include_directories is set to: ${PROJECT_SOURCE_DIR}/../../")
