cmake_minimum_required(VERSION 3.10)

project(ContactManager CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(contacts
    src/main.cpp
    src/contact.cpp
    src/contact_manager.cpp
)

target_include_directories(contacts PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
