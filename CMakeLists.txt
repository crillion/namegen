
cmake_minimum_required (VERSION 2.8.11)
project (test_namegen)

# set here where you have your compiled boost
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "D:/data/Users/crillion/data/projects/external/boost")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "D:/data/Users/crillion/data/projects/external/boost")

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  ADD_DEFINITIONS( "-DHAS_BOOST" )
endif()

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (test_namegen test_namegen.cpp)
