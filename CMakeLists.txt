cmake_minimum_required(VERSION 3.23)

set(project OOP_project)

project(${project})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_subdirectory(task)
add_compile_options("${compile_opts}" ${GTK4_CFLAGS_OTHER})

set(SOURCES main.cpp)

add_executable(project ${SOURCES})

target_link_libraries(project ${GTK4_LIBRARIES} task)