cmake_minimum_required(VERSION 3.23)

project (manadger)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})


set(SOURCES main.cpp sources/users_data.cpp sources/user_pick_window.cpp sources/mainwindow.cpp sources/sectionwindow.cpp sources/operation.cpp sources/PieChart.cpp)

set(HEADERS  headers/users_data.h headers/user_pick_window.h headers/mainwindow.h headers/sectionwindow.h headers/operation.h headers/PieChart.h)

set(SOURCES_LIST ${SOURCES} ${HEADERS})
add_executable(manadger ${SOURCES_LIST})

target_link_libraries(manadger ${GTKMM_LIBRARIES})



