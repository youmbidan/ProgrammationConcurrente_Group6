# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = masterchef_info

# Indique les fichiers source
SOURCES += main.cpp \
    kitchenwindow.cpp \
    restauranttab.cpp \
    src/Controllers/classDeclaration/* \
    src/Controllers/classDefinition/* \
    src/Models/classDeclaration/* \
    src/Models/classDefinition/* \
    src/View/mainview.cpp
# Indique l'utilisation des modules Qt nécessaires
QT += widgets
QT += core gui

# Configuration spécifique à MinGW
CONFIG += c++17

# Inclut les répertoires nécessaires
INCLUDEPATH += .

RESOURCES += \
    ressources.qrc

HEADERS += \
    kitchenwindow.h \
    restauranttab.h

