cmake_minimum_required(VERSION 3.14)

project(boat LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(boat SHARED
  boat_global.h
  boat.cpp
  boat.h
  ../../transport.cpp ../../transport.h
  ../water_transport/water_transport_global.h
  ../water_transport/water_transport.h ../water_transport/water_transport.cpp
)

target_link_libraries(boat PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(boat PRIVATE BOAT_LIBRARY)
