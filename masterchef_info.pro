# Déclare le type et le nom du projet
TEMPLATE = app
TARGET = masterchef_info

# Indique les fichiers source
SOURCES += main.cpp src/

# Indique l'utilisation des modules Qt nécessaires
QT += widgets
QT += core gui

# Configuration spécifique à MinGW
CONFIG += c++17

# Inclut les répertoires nécessaires
INCLUDEPATH += .

RESOURCES += \
    ressources.qrc

