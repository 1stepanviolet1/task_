cmake_minimum_required(VERSION 3.20)

project(app VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("./headers")

aux_source_directory("./src" CORE)

add_executable(app
  ${CORE}
)

