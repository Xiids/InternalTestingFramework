cmake_minimum_required(VERSION 3.11)
project(PerformanceTestcpp)

set(CMAKE_CXX_STANDARD 20)
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
    ${PROJECT_SOURCE_DIR}/commandParameterHanding_test_main.cxx
    ${PROJECT_SOURCE_DIR}/../../src/runTime/commandParameterHanding.cxx
    ${PROJECT_SOURCE_DIR}/../../src/runTime/parameterHandling.cxx
)



add_definitions(-DRTI_LINUX -DRTI_UNIX -Dm64)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../../
                                                   ${PROJECT_SOURCE_DIR}/../../runTime/)
target_link_libraries(${PROJECT_NAME} 
                        nddscpp2  
                        nddsc 
                        nddscore 
)

# message(STATUS "target_include_directories is set to: ${PROJECT_SOURCE_DIR}/../../")
