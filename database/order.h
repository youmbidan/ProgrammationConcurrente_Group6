#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>
#include "Recipe.h"

class Order {
public:
    int id;
    QString details;
    QList<Recipe> recipes;

    Order(int id = 0, QString details = "")
        : id(id), details(details) {}

    int getTotalCookingTime() const {
        int total = 0;
        for (const Recipe& recipe : recipes) {
            total += recipe.cookingTime;
        }
        return total;
    }
};

#endif // ORDER_H
