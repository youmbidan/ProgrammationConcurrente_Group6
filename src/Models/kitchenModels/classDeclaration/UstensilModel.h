#ifndef USTENSILMODEL_H
#define USTENSILMODEL_H

#include <QString>

class UstensilModel {
public:
    QString name; // Nom de l'ustensile
    int washTime; // Temps de lavage en secondes

    UstensilModel(); // Constructeur par défaut
    UstensilModel(QString name, int washTime);

    QString toString() const; // Pour un affichage lisible
};

#endif // USTENSILMODEL_H
