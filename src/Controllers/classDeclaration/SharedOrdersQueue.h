//
// Created by seand on 12/13/2024.
//

#ifndef SHAREDQUEUES_H
#define SHAREDQUEUES_H


#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>

#include "../../Models/commonModels/classDeclaration/Order.h"

class SharedOrdersQueue {
public:
    void addOrder(const Order& order);
    Order getOrder();
    bool isEmpty();

private:
    std::queue<Order> ordersQueue;
    std::mutex queueMutex;
    std::condition_variable queueCondition;
};


#endif //SHAREDQUEUES_H
