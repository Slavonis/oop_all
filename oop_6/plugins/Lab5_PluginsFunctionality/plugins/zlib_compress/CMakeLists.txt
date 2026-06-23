set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_library(ZlibCompressPlugin SHARED ZlibCompressPlugin.cpp
    ../../include/plugin/IProcessorPlugin.hpp)
target_include_directories(ZlibCompressPlugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ZlibCompressPlugin Qt6::Widgets)
set_target_properties(ZlibCompressPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins")
