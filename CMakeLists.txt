cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(tomatoes-client)


add_executable(${PROJECT_NAME} src/main.cpp src/xdg.cpp src/Session.cpp src/Network.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE src)

## DEPENDENCIES
find_package(cpprestsdk REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)

