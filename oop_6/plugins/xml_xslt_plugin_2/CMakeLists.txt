cmake_minimum_required(VERSION 3.14)

project(xml_xslt_plugin_2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core Xml)

add_library(xml_xslt_plugin_2 SHARED
  xml_xslt_plugin_2_global.h
  xml_xslt_plugin_2.cpp
  xml_xslt_plugin_2.h
  ../../proc_interface.cpp ../../proc_interface.h
)

target_link_libraries(xml_xslt_plugin_2 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_link_libraries(xml_xslt_plugin_2 PRIVATE Qt6::Core Qt6::Xml)

target_compile_definitions(xml_xslt_plugin_2 PRIVATE XML_XSLT_PLUGIN_2_LIBRARY)
