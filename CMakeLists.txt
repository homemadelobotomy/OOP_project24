cmake_minimum_required(VERSION 3.23)

project (manadger)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})


add_executable(manadger main.cpp headers/user_pick_window.h headers/users_data.h  sources/user_pick_window.cpp sources/users_data.cpp)

target_link_libraries(manadger ${GTKMM_LIBRARIES})



