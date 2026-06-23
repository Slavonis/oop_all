set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_library(IdentityPlugin SHARED IdentityPlugin.cpp)
target_include_directories(IdentityPlugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(IdentityPlugin Qt6::Widgets)
set_target_properties(IdentityPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins")
