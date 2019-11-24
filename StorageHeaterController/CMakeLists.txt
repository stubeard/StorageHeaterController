cmake_minimum_required(VERSION 3.14.1)
project (StorageHeaterController)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(StorageHeaterController main.cpp ConsoleView.cpp HeaterControlModel.cpp PresentationLayer.cpp)