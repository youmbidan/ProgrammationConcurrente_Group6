cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(masterchef_info LANGUAGES CXX)

# Définit la version minimale de Qt requise
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\mingw_64\\")

# Rechercher les modules nécessaires de Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

set(CMAKE_AUTOMOC ON)

# Ajoutez les ressources
qt_add_resources(RESOURCES ressources.qrc)


# Ajouter l'exécutable
add_executable(masterchef_info main.cpp
        src/Controllers/classDeclaration/MainController.h
        src/Controllers/classDeclaration/DBController.h
        src/Controllers/classDeclaration/MotionlessElementController.h
        src/Controllers/classDefinition/MainController.cpp
        src/Controllers/classDefinition/DBController.cpp
#        src/Controllers/classDefinition/MotionlessElementController.cpp
#        src/Models/kitchenModels/classDefinition/DirtyDishesStorage.cpp
#        src/Models/kitchenModels/classDefinition/WashingMachine.cpp
#        src/Models/kitchenModels/classDeclaration/DirtyDishesStorage.h
#        src/Models/kitchenModels/classDeclaration/WashingMachine.h
        src/Views/mainView.h
        src/Views/mainView.cpp
        src/Views/MobilePointView.cpp
        src/Views/MobilePointView.h
        src/Models/MobilePointModel.cpp
        src/Models/MobilePointModel.h
        src/Observer/Observable.cpp
        src/Structs/PointStruct.h
#        src/Controllers/classDefinition/CharacterElementController.cpp
#        src/Controllers/classDeclaration/CharacterElementController.h
#        src/Controllers/classDefinition/CharacterElementController.cpp
#        src/Models/dinningRoomModels/classDefinition/HeadWaiter.cpp
#        src/Models/dinningRoomModels/classDefinition/Server.cpp
#        src/Models/dinningRoomModels/classDefinition/RoomClerk.cpp
#        src/Factories/classDefinition/TableFactory.cpp
#        src/Factories/classDefinition/TableFactory.cpp
#        src/Factories/classDeclaration/TableFactory.h
#        src/Factories/classDeclaration/ServerFactory.h
#        src/Factories/classDefinition/ServerFactory.cpp
        src/Views/kitchenView/kitchenView.cpp
        src/Views/dinningRoomView/dinningRoomView.cpp
        src/Views/dashboardView/Dashboard.cpp
        src/Views/SetupView/SetupView.cpp
        src/Views/SetupView/SetupView.h

        ${RESOURCES}
        main.cpp
        src/kitchen/chefcontroller.cpp src/kitchen/chefcontroller.h src/kitchen/chefmodel.cpp src/kitchen/chefmodel.h src/kitchen/chefview.cpp src/kitchen/chefview.h src/kitchen/cookmodel.cpp src/kitchen/cookmodel.h src/kitchen/mysqlconnection.h src/kitchen/order.cpp src/kitchen/order.h src/kitchen/recipe.cpp src/kitchen/recipe.h src/kitchen/ustensilmodel.cpp src/kitchen/ustensilmodel.h
)

# Lier l'exécutable aux bibliothèques Qt nécessaires
target_link_libraries(masterchef_info PRIVATE Qt6::Widgets Qt6::Sql)
