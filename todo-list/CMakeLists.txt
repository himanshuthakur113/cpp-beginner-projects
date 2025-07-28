cmake_minimum_required(VERSION 3.10)

project(todo-list)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(todo-list
    src/date.cpp
    src/task.cpp
    src/todo_list.cpp
    src/main.cpp
)

target_include_directories(todo-list PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
