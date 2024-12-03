cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(masterchef_info LANGUAGES CXX)

# Définit la version minimale de Qt requise
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Rechercher les modules nécessaires de Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Ajouter l'exécutable
add_executable(masterchef_info main.cpp)

# Lier l'exécutable aux bibliothèques Qt nécessaires
target_link_libraries(masterchef_info PRIVATE Qt6::Widgets)