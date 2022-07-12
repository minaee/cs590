cmake_minimum_required(VERSION 3.0.0)
project(cs590 VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCES
    header/*.h
    source/*.cpp
)

add_library(src SHARED ${SOURCES})
target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header")

add_executable(cs590 main.cpp)
target_link_libraries(cs590 src)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
