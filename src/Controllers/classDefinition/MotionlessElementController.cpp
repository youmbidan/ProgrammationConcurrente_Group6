#include "../classDeclaration/MotionlessElementController.h"

#include "../../Factories/classDeclaration/TableFactory.h"
//
// Created by franck on 12/2/24.
//
MotionlessElementController::MotionlessElementController(DinningRoomView *dinningRoomView) : dinning_room_view(dinningRoomView){
    this->tableSize = 80;
    this->cols = 5;
    this->rows = 5;

    this->sectionWidth = (cols * tableSize) + (cols + 1) * 30;
    this->sectionHeight = (rows * tableSize) + (rows + 1) * 30;
    this->totalWidth = 2 * sectionWidth;
    this->totalHeight = sectionHeight + 50;
    this->newSpacingX = (sectionWidth - (cols * tableSize)) / (cols + 1);
    this->newSpacingY = (sectionHeight - (rows * tableSize)) / (rows + 1);
};

void MotionlessElementController::createAllTable() {
    //create table for the first area
    arrangeSection(0,0,15,1);
    //create table for the second area
    arrangeSection(sectionWidth,15,30,2);

}

void MotionlessElementController::createKitchenElements() {
    // TODO: add few instructions to manage it
}


void MotionlessElementController::arrangeSection(int xOffset, int tableCountStart, int tableCountEnd, int area) {
    int row = 0, col = 0;
    PointStruct coord = calculateCoordinate(newSpacingX, tableSize, col, row, xOffset);
    for (int i = tableCountStart; i < tableCountEnd; ++i) {
        if (i < tableCountStart + 5) {
            //get a new instance of table via the factory
            TableFactory::getTableOfTwo(coord.x, coord.y, area);
            //use the addTable__ToDinningRoomScene() to insert new table on scene
            dinning_room_view.addTableTwoToDinningRoomScene(coord.x, coord.y);
        } else if (i < tableCountStart + 10) {
            TableFactory::getTableOfTwo(coord.x, coord.y, area);
            dinning_room_view.addTableFourToDinningRoomScene(coord.x, coord.y);
        } else if (i < tableCountStart + 12) {
            TableFactory::getTableOfSix(coord.x, coord.y, area);
            dinning_room_view.addTableSixToDinningRoomScene(coord.x, coord.y);
        } else {
            TableFactory::getTableOfEight(coord.x, coord.y, area);
            dinning_room_view.addTableHeightToDinningRoomScene(coord.x, coord.y);
        }

        if (++col >= cols) {
            col = 0;
            row++;
        }
    }
}


PointStruct MotionlessElementController::calculateCoordinate(int newSpacingX, int tableSize, int col, int row,
                                                              int xOffset) const {
    double x = xOffset + col * (tableSize + newSpacingX);
    double y = 210 + row * (tableSize + newSpacingY);
    PointStruct coord = {x, y};
    return coord;
};


