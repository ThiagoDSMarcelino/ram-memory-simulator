cmake_minimum_required(VERSION 3.14)

set(This CardsGame)

project(${This})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(SRCS
  ${SRC_DIR}/main.c
  ${SRC_DIR}/memory.c
)

add_executable(program ${SRCS})

set_target_properties(program PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)