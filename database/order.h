#ifndef ORDER_H
#define ORDER_H

#include <QString>

class Order {
public:
    int id;
    QString details;

    Order(int id = 0, QString details = "")
        : id(id), details(details) {}
};

#endif // ORDER_H
