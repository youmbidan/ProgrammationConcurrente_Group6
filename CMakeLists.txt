cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(masterchef_info LANGUAGES CXX)

# Définit la version minimale de Qt requise
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Rechercher les modules nécessaires de Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)

# Ajouter l'exécutable
add_executable(masterchef_info main.cpp
    src/Controllers/classDeclaration/MainController.h 
    src/Controllers/classDeclaration/DBController.h 
    src/Controllers/classDeclaration/MotionlessElementController.h 
    src/Controllers/classDefinition/MainController.cpp 
    src/Controllers/classDefinition/DBController.cpp 
    src/Controllers/classDefinition/MotionlessElementController.cpp
    src/Models/kitchenModels/classDefinition/DirtyDishesStorage.cpp
    src/Models/kitchenModels/classDefinition/WashingMachine.cpp
    src/Models/kitchenModels/classDeclaration/DirtyDishesStorage.h
    src/Models/kitchenModels/classDeclaration/WashingMachine.h
    src/Views/mainView.h
    src/Views/mainView.cpp
        src/Views/MobilePointView.cpp
        src/Views/MobilePointView.h
        src/Models/MobilePointModel.cpp
        src/Models/MobilePointModel.h
        src/Observer/Observable.cpp
        src/Structs/PointStruct.cpp
)

# Lier l'exécutable aux bibliothèques Qt nécessaires
target_link_libraries(masterchef_info PRIVATE Qt6::Widgets)