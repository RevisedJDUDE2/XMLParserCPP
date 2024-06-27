cmake_minimum_required(VERSION 3.29.3)

project(XML_PARSE VERSION 1.1)

file(GLOB_RECURSE SRC_FILES "src/lib/*.cpp")

add_library(XML_PARSE SHARED ${SRC_FILES})

target_include_directories(XML_PARSE PUBLIC "include/lib")

project(SAMPLE_PARSER VERSION 1.1)

file(GLOB_RECURSE SRC_FILES_SAMPLE "src/*.cpp")

add_executable(SAMPLE_PARSER ${SRC_FILES_SAMPLE})

target_include_directories(SAMPLE_PARSER PUBLIC "./include")

target_link_libraries(SAMPLE_PARSER PUBLIC XML_PARSE)