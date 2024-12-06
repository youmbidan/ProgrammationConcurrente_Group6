//
// Created by franck on 12/2/24.
//

#ifndef MOVECONTROLLER_H
#define MOVECONTROLLER_H
#include "../../Models/dinningRoomModels/classDeclaration/headWaiter.h"
#include "../../Models/kitchenModels/classDeclaration/RestaurantDiver.h"
#include "../../Models/dinningRoomModels/classDeclaration/Server.h"
using namespace std;
class MoveController {
public:
    void moveServer(Server server);
    void moveHeadWaiter(HeadWaiter headWaiter);
    void moveRestaurantDiver(RestaurantDiver restaurantDiver);
    // TODO: add the rest of the move method
};
#endif //MOVECONTROLLER_H
