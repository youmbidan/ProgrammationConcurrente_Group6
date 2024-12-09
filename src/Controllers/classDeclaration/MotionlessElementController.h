//
// Created by franck on 12/2/24.
//

#ifndef MOTIONLESSELEMENTCONTROLLER_H
#define MOTIONLESSELEMENTCONTROLLER_H
#include "../../Models/kitchenModels/classDeclaration/DirtyDishesStorage.h"
#include "../../Models/kitchenModels/classDeclaration/WashingMachine.h"
#include "../../Structs/PointStruct.h"
#include "../../Views/dinningRoomView/DinningRoomView.h"
using namespace std;

/**
 * @class MotionlessElementController
 *
 * @brief initialize motionlessElements on screen such as Table, dishWasher
 * and washing machine
 *
 */
class MotionlessElementController {
public:
    /**
     * 
     * @param dinningRoomView
     */
    explicit MotionlessElementController(DinningRoomView *dinningRoomView);

    void createAllTable();
    void createKitchenElements();

private:
    /**
     * 
     * @param xOffset 
     * @param tableCountStart 
     * @param tableCountEnd 
     * @param area 
     */
    void arrangeSection(int xOffset, int tableCountStart, int tableCountEnd, int area);

    /**
     * 
     * @param newSpacingX
     * @param tableSize 
     * @param col 
     * @param row 
     * @param xOffset 
     * @return 
     */
    PointStruct calculateCoordinate(int newSpacingX, int tableSize, int col, int row, int xOffset) const;

    DinningRoomView *dinning_room_view;

    int tableSize;
    int cols;
    int rows;

    int sectionWidth;
    int sectionHeight;
    int totalWidth;
    int totalHeight;

    int newSpacingX;
    int newSpacingY;


    DirtyDishesStorage dirty_dishes_storage_;
    WashingMachine washing_machine_;
};
#endif //MOTIONLESSELEMENTCONTROLLER_H
