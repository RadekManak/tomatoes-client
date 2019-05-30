cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(tomatoes-client)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/xdg.cpp
        src/Session.cpp
        src/Network.cpp
        src/Console.cpp
        src/qt/MainWindow.cpp
        src/qt/MainWindow.ui
        src/qt/TimerWidget.cpp
        src/qt/TimerWidget.ui
        src/qt/SubmitWidget.cpp
        src/qt/SubmitWidget.ui
        )

## DEPENDENCIES
find_package(cpprestsdk REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)

find_package(Qt5Widgets CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)