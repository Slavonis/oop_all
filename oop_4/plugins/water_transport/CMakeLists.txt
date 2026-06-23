cmake_minimum_required(VERSION 3.14)

project(water_transport LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(water_transport SHARED
  water_transport_global.h
  water_transport.cpp
  water_transport.h
  ../../transport.h
  ../../transport.cpp
)

target_link_libraries(water_transport PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(water_transport PRIVATE WATER_TRANSPORT_LIBRARY)
