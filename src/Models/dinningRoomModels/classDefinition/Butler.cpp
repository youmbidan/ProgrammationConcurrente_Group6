#include "../classDeclaration/Butler.h"

// Mutex pour protéger l'accès à la liste des tables libres

Table* Butler::assignTable(int clientNumber, vector<Table*>& freeTableList) {
    Table* selectedTable = nullptr;

    // Protection par mutex pour éviter les problèmes de concurrence
    std::unique_lock<std::mutex> lock(freeTablesMutex);

    // Afficher les tables disponibles pour debug
    std::cout << "Tables disponibles avant recherche : ";
    for (Table* table : freeTableList) {
        if (table) {
            std::cout << table->getCapacity() << " ";
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;

    // Parcourir la liste des tables pour trouver la plus petite table suffisante
    for (Table* table : freeTableList) {
        if (table && table->getCapacity() >= clientNumber) {
            // Vérifier si c'est la plus petite table suffisante trouvée jusqu'ici
            if (!selectedTable || table->getCapacity() < selectedTable->getCapacity()) {
                selectedTable = table;
            }
        }
    }

    // Si une table est trouvée, la retirer de la liste des tables libres
    if (selectedTable) {
        std::cout << "Table trouvée : capacité = " << selectedTable->getCapacity() << std::endl;
        freeTableList.erase(std::remove(freeTableList.begin(), freeTableList.end(), selectedTable), freeTableList.end());
    } else {
        std::cerr << "Aucune table disponible pour " << clientNumber << " clients." << std::endl;
    }

    return selectedTable;
}

