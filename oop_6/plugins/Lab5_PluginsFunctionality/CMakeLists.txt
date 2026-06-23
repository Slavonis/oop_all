cmake_minimum_required(VERSION 3.16)
project(Lab5_PluginsFunctionality)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include_directories(include)

add_library(VehicleLib SHARED
    src/model/Vehicle.cpp src/model/Car.cpp src/model/Bike.cpp
    src/model/Truck.cpp   src/model/Bus.cpp src/model/Motorcycle.cpp
    src/model/ElectricScooter.cpp src/factory/VehicleFactory.cpp
)
target_link_libraries(VehicleLib Qt6::Widgets)

add_executable(${PROJECT_NAME}
    main.cpp src/ui/MainWindow.cpp src/ui/EditVehicleDialog.cpp
)
target_link_libraries(${PROJECT_NAME} VehicleLib Qt6::Widgets)

add_subdirectory(plugins/van)
add_subdirectory(plugins/zlib_compress)
add_subdirectory(plugins/identity)
