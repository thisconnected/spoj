cmake_minimum_required(VERSION 3.14)

# set the project name
project(myspoj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_SHARED_LIBRARY_PREFIX "")




set($CMAKE_SOURCE_DIR .)


add_compile_options(-Wall)
add_compile_options(-g)
add_compile_options(-Wextra)


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/addrev)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/johnny)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/asseco)
