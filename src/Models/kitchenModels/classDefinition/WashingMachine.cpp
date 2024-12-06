#include "../classDeclaration/WashingMachine.h"
//
// Created by franck on 12/2/24.
//

WashingMachine::WashingMachine(){};

int WashingMachine::getTowelsNumber() {
    return towelsNumber;
}
void WashingMachine::setTowelsNumber(int towels_number) {
    this->towelsNumber = towels_number;
}

