#include "UstensilModel.h"

UstensilModel::UstensilModel()
    : name("Unknown"), washTime(0) {}

UstensilModel::UstensilModel(QString name, int washTime)
    : name(name), washTime(washTime) {}

QString UstensilModel::toString() const {
    return QString("Ustensile: %1, Temps de lavage: %2 secondes").arg(name).arg(washTime);
}
