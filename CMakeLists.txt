cmake_minimum_required(VERSION 3.20)
set(CMAKE_CPP_COMPILER clang++)
set(CMAKE_CPP_STANDARD 17)

project(app)

include_directories("./headers")

aux_source_directory("./src" CORE)

add_executable(app
  ${CORE}
)

