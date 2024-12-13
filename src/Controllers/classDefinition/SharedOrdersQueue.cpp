#include "../classDeclaration/SharedOrdersQueue.h"

void SharedOrdersQueue::addOrder(const Order& order) {
    std::cout << "............. COMMANDE ENVOYEE EN CUISINE ..............." << std::endl;
    std::lock_guard<std::mutex> lock(queueMutex);  // Protéger l'accès à la queue
    ordersQueue.push(order);
    queueCondition.notify_one();
}

Order SharedOrdersQueue::getOrder() {
    std::unique_lock<std::mutex> lock(queueMutex);
    queueCondition.wait(lock, [this] { return !ordersQueue.empty(); });  // Attente jusqu'à ce qu'il y ait des commandes
    Order order = ordersQueue.front();
    std::cout << "............. COMMANDE RECUPEREE PAR CUISINE ..............." << std::endl;
    ordersQueue.pop();
    return order;
}

bool SharedOrdersQueue::isEmpty() {
    std::lock_guard<std::mutex> lock(queueMutex);  // Protéger l'accès à la queue
    return ordersQueue.empty();
}
