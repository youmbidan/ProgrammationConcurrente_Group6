#ifndef ORDER_H
#define ORDER_H
#include <QMap>
#include <QString>
#include <QList>
#include <QSet>
#include "Recipe.h"

class Order {
public:
    int id;
    QString details;
    QMap<Recipe, int> recipesWithQuantities; // Recipe avec quantité

    // Constructeur par défaut
    Order() : id(0), details("") {}

    // Constructeur paramétré
    Order(int id, const QString& details)
        : id(id), details(details) {}

    QList<QString> getIngredients() const {
        QList<QString> ingredients;
        for (auto it = recipesWithQuantities.cbegin(); it != recipesWithQuantities.cend(); ++it) {
            const Recipe& recipe = it.key();
            int quantity = it.value();
            for (int i = 0; i < quantity; ++i) {
                ingredients.append(recipe.getIngredients());
            }
        }
        return ingredients;
    }

    QList<QString> getUstensils() const {
        QList<QString> ustensils;
        for (auto it = recipesWithQuantities.cbegin(); it != recipesWithQuantities.cend(); ++it) {
            const Recipe& recipe = it.key();
            int quantity = it.value();
            for (int i = 0; i < quantity; ++i) {
                ustensils.append(recipe.getUstensils());
            }
        }
        return ustensils;
    }

    int getTotalCookingTime() const {
        int total = 0;
        for (auto it = recipesWithQuantities.cbegin(); it != recipesWithQuantities.cend(); ++it) {
            total += it.key().getCookingTime() * it.value();
        }
        return total;
    }
};

#endif // ORDER_H
