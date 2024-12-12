cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(masterchef_info LANGUAGES CXX)

# Définit la version minimale de Qt requise
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Rechercher les modules nécessaires de Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Ajoutez les ressources
qt_add_resources(RESOURCES ressources.qrc)

# Ajouter l'exécutable
add_executable(masterchef_info
        main.cpp
        src/Controllers/classDeclaration/MainController.h
        src/Controllers/classDefinition/MainController.cpp
        src/Controllers/classDeclaration/DBController.h
        src/Controllers/classDefinition/DBController.cpp
        src/Controllers/classDeclaration/MotionlessElementController.h
        src/Controllers/classDefinition/MotionlessElementController.cpp
        src/Controllers/classDeclaration/CharacterElementController.h
        src/Controllers/classDefinition/CharacterElementController.cpp
        src/Controllers/classDeclaration/DinningRoomController.h
        src/Controllers/classDefinition/DinningRoomController.cpp
        src/Models/kitchenModels/classDeclaration/DirtyDishesStorage.h
        src/Models/kitchenModels/classDefinition/DirtyDishesStorage.cpp
        src/Models/kitchenModels/classDeclaration/WashingMachine.h
        src/Models/kitchenModels/classDefinition/WashingMachine.cpp
        src/Models/dinningRoomModels/classDefinition/HeadWaiter.cpp
        src/Models/dinningRoomModels/classDefinition/Server.cpp
        src/Models/dinningRoomModels/classDefinition/RoomClerk.cpp
        src/Models/dinningRoomModels/classDefinition/Table.cpp
        src/Models/commonModels/classDeclaration/MobileElementModel.h
        src/Models/commonModels/classDefinition/MobileElementModel.cpp
        src/Models/commonModels/classDeclaration/ClientGroupModel.h
        src/Models/commonModels/classDefinition/ClientGroupModel.cpp
        src/Models/commonModels/classDefinition/ClientModel.cpp
        src/Models/commonModels/classDeclaration/Order.h
        src/Models/commonModels/classDefinition/Order.cpp
        src/Factories/classDeclaration/TableFactory.h
        src/Factories/classDefinition/TableFactory.cpp
        src/Factories/classDeclaration/ClientGroupFactory.h
        src/Factories/classDefinition/ClientGroupFactory.cpp
        src/Views/mainView.h
        src/Views/mainView.cpp
        src/Views/CommonPointView.h
        src/Views/CommonPointView.cpp
        src/Views/kitchenView/kitchenView.cpp
        src/Views/dinningRoomView/dinningRoomView.cpp
        src/Views/dinningRoomView/DinningRoomView.h
        src/Observer/Observable.cpp
        src/Structs/PointStruct.h
        src/Utilities/ThreadPoolManager.h
        src/Utilities/ThreadPoolManager.cpp
        ${RESOURCES}
        src/Models/commonModels/classDeclaration/DinningRoom.h
        src/Models/commonModels/classDefinition/DinningRoom.cpp
        src/Models/dinningRoomModels/classDefinition/Butler.cpp
        src/Structs/Attribution.h
        src/Enums/RecipesNames.h
        src/Enums/RecipesTypes.h
        src/Models/commonModels/classDefinition/CardModel.cpp
        src/Models/commonModels/classDefinition/Recipe.cpp
        src/Structs/orderRecipe.h
)

# Lier l'exécutable aux bibliothèques Qt nécessaires
target_link_libraries(masterchef_info PRIVATE Qt6::Widgets
        Threads::Threads)

target_link_libraries(masterchef_info PRIVATE winpthread)



