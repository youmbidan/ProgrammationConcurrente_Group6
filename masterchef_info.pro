# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = masterchef_info

# Fichiers source
SOURCES += \
    main.cpp \
    src/Controllers/classDeclaration/MainController.h \
    src/Controllers/classDeclaration/DBController.h \
    src/Controllers/classDeclaration/MotionlessElementController.h \
    src/Controllers/classDefinition/MainController.cpp \
    src/Controllers/classDefinition/DBController.cpp \
#        src/Controllers/classDefinition/MotionlessElementController.cpp
#        src/Models/kitchenModels/classDefinition/DirtyDishesStorage.cpp
#        src/Models/kitchenModels/classDefinition/WashingMachine.cpp
#        src/Models/kitchenModels/classDeclaration/DirtyDishesStorage.h
#        src/Models/kitchenModels/classDeclaration/WashingMachine.h
    src/Views/dinningRoomView/DinningRoomView.cpp \
    src/Views/dinningRoomView/DinningRoomView.h \
    src/Views/mainView.h \
    src/Views/mainView.cpp \
    src/Views/MobilePointView.cpp \
    src/Views/MobilePointView.h \
    src/Models/MobilePointModel.cpp \
    src/Models/MobilePointModel.h \
    src/Observer/Observable.cpp \
    src/Structs/PointStruct.h \
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
src/Views/dinningRoomView/DinningRoomView.cpp \
src/Views/dinningRoomView/DinningRoomView.h \
    src/Views/kitchenView/KitchenView.cpp \
    src/Views/kitchenView/KitchenView.h \




# Ajout des fichiers ressources
RESOURCES += ressources.qrc

# Modules Qt nécessaires
QT += widgets gui
QT += charts

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
    src/Views/dinningRoomView \
    src/Views/dashboardView \
    src/Views/SetupView \
   
    src/Views/kitchenView
