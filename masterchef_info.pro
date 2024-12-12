# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = masterchef_info

# Fichiers source
SOURCES += \
src/Controllers/classDefinition/CharacterElementController.cpp \
    src/Controllers/classDefinition/DBController.cpp \
    src/Controllers/classDefinition/DinningRoomController.cpp \
    src/Controllers/classDefinition/MainController.cpp \
    src/Controllers/classDefinition/MotionlessElementController.cpp \
    src/Controllers/classDefinition/MoveController.cpp \
    src/Models/commonModels/classDefinition/CardModel.cpp \
    src/Models/commonModels/classDefinition/ClientGroupModel.cpp \
    src/Models/commonModels/classDefinition/ClientModel.cpp \
    src/Models/commonModels/classDefinition/DinningRoom.cpp \
    src/Models/commonModels/classDefinition/KitchenCounter.cpp \
    src/Models/commonModels/classDefinition/MaterialModel.cpp \
    src/Models/commonModels/classDefinition/MobileElementModel.cpp \
    src/Models/commonModels/classDefinition/Order.cpp \
    src/Models/commonModels/classDefinition/Recipe.cpp \
    src/Models/commonModels/classDefinition/UstensilModel.cpp \
    src/Models/dinningRoomModels/classDefinition/Butler.cpp \
    src/Models/dinningRoomModels/classDefinition/HeadWaiter.cpp \
    src/Models/dinningRoomModels/classDefinition/RoomClerk.cpp \
    src/Models/dinningRoomModels/classDefinition/Server.cpp \
    src/Models/dinningRoomModels/classDefinition/Table.cpp \
    src/Models/kitchenModels/classDefinition/Chief.cpp \
    src/Models/kitchenModels/classDefinition/Cook.cpp \
    src/Models/kitchenModels/classDefinition/DirtyDishesStorage.cpp \
    src/Models/kitchenModels/classDefinition/DishwasherModel.cpp \
    src/Models/kitchenModels/classDefinition/KitchenAssistant.cpp \
    src/Models/kitchenModels/classDefinition/RestaurantDiver.cpp \
    src/Models/kitchenModels/classDefinition/StorageModel.cpp \
    src/Models/kitchenModels/classDefinition/WashingMachine.cpp \
    src/Views/dinningRoomView/DinningRoomView.cpp \
    src/Views/kitchenView/KitchenView.cpp \
    src/Views/CommonPointView.cpp \
    src/Views/MainView.cpp \
    src/Views/dashboardView/Dashboard.cpp \
    src/Views/dinningRoomView/DinningRoomView.cpp \
    src/Views/kitchenView/KitchenView.cpp \
    src/Views/SetupView/SetupView.cpp \
    src/Observer/Observable.cpp \
    src/Factories/classDefinition/ClientGroupFactory.cpp \
    src/Factories/classDefinition/ServerFactory.cpp \
    src/Factories/classDefinition/TableFactory.cpp

# Fichiers header
HEADERS += \
src/Controllers/classDeclaration/CharacterElementController.h \
    src/Controllers/classDeclaration/DBController.h \
    src/Controllers/classDeclaration/DinningRoomController.h \
    src/Controllers/classDeclaration/MainController.h \
    src/Controllers/classDeclaration/MotionlessElementController.h \
    src/Controllers/classDeclaration/MoveController.h \
    src/Models/commonModels/classDeclaration/CardModel.h \
    src/Models/commonModels/classDeclaration/ClientGroupModel.h \
    src/Models/commonModels/classDeclaration/ClientModel.h \
    src/Models/commonModels/classDeclaration/DinningRoom.h \
    src/Models/commonModels/classDeclaration/MobileElementModel.h \
    src/Models/commonModels/classDeclaration/Order.h \
    src/Models/commonModels/classDeclaration/Recipe.h \
    src/Models/dinningRoomModels/classDeclaration/Butler.h \
    src/Models/dinningRoomModels/classDeclaration/headWaiter.h \
    src/Models/dinningRoomModels/classDeclaration/RoomClerk.h \
    src/Models/dinningRoomModels/classDeclaration/Server.h \
    src/Models/dinningRoomModels/classDeclaration/Table.h \
    src/Models/kitchenModels/classDeclaration/Chief.h \
    src/Models/kitchenModels/classDeclaration/Cook.h \
    src/Models/kitchenModels/classDeclaration/DirtyDishesStorage.h \
    src/Models/kitchenModels/classDeclaration/DishwasherModel.h \
    src/Models/kitchenModels/classDeclaration/KitchenAssistant.h \
    src/Models/kitchenModels/classDeclaration/KitchenCounter.h \
    src/Models/kitchenModels/classDeclaration/MaterialModel.h \
    src/Models/kitchenModels/classDeclaration/RestaurantDiver.h \
    src/Models/kitchenModels/classDeclaration/StorageModel.h \
    src/Models/kitchenModels/classDeclaration/UstensilModel.h \
    src/Models/kitchenModels/classDeclaration/WashingMachine.h \
    src/Views/dinningRoomView/DinningRoomView.h \
    src/Views/kitchenView/KitchenView.h \
    src/Views/CommonPointView.h \
    src/Views/MainView.h \
    src/Views/dashboardView/Dashboard.h \
    src/Views/dinningRoomView/DinningRoomView.h \
    src/Views/kitchenView/KitchenView.h \
    src/Views/SetupView/SetupView.h \
    src/Structs/Attribution.h \
    src/Structs/OrderRecipe.h \
    src/Structs/PointStruct.h \
    src/Observer/Observable.h \
    src/Observer/Observer.h \
    src/Factories/classDeclaration/ClientGroupFactory.h \
    src/Factories/classDeclaration/TableFactory.h

# Ajout des fichiers ressources
RESOURCES += ressources.qrc

# Modules Qt nécessaires
QT += widgets gui

# Configuration spécifique
CONFIG += c++17

# Répertoires d'inclusion
INCLUDEPATH += \
src/Controllers/classDeclaration \
    src/Controllers/classDefinition \
    src/Factories/classDeclaration \
    src/Factories/classDefinition \
    src/Models/commonModels/classDeclaration \
    src/Models/commonModels/classDefinition \
    src/Models/dinningRoomModels/classDeclaration \
    src/Models/dinningRoomModels/classDefinition \
    src/Models/kitchenModels/classDeclaration \
    src/Models/kitchenModels/classDefinition \
    src/Observer \
    src/Structs \
    src/Views \
    src/Views/SetupView \
    src/Views/dashboardView \
    src/Views/dinningRoomView \
    src/Views/kitchenView
