set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_library(VanPlugin SHARED Van.cpp VanPlugin.cpp)
target_include_directories(VanPlugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(VanPlugin VehicleLib Qt6::Widgets)
set_target_properties(VanPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins")
