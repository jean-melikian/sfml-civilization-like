cmake_minimum_required(VERSION 3.7)
project(my_civilization)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp models/Unit.cpp models/Unit.hpp helpers/TextBuilder.cpp helpers/TextBuilder.hpp entities/TileMap.cpp entities/TileMap.hpp helpers/Constants.hpp models/SwordsmanUnit.cpp models/SwordsmanUnit.hpp)
add_executable(my_civilization ${SOURCE_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(my_civilization ${SFML_LIBRARIES})
endif ()