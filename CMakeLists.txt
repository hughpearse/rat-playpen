cmake_minimum_required(VERSION 2.8)

project(rat)

file(GLOB SOURCES src/*.c)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(get ${SOURCES})

find_package (CURL)
if (CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIRS})
  target_link_libraries (get ${CURL_LIBRARIES})
endif (CURL_FOUND)
