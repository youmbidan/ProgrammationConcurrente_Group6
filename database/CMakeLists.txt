cmake_minimum_required(VERSION 3.16)

project(database VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    MANUAL_FINALIZATION
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(database
        ${PROJECT_SOURCES}

        chefmodel.h chefmodel.cpp
        cookmodel.h cookmodel.cpp
        chefcontroller.h chefcontroller.cpp
        chefview.h chefview.cpp
        order.h order.cpp
        recipe.h recipe.cpp

    )
else()
    add_executable(database
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(database)
endif()

message("Projet configuré avec succès pour Qt ${QT_VERSION_MAJOR}.")
