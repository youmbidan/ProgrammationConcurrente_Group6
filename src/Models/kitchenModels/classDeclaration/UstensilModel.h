//
// Created by franck on 12/2/24.
//

#ifndef USTENSILMODEL_H
#define USTENSILMODEL_H
#include <iostream>
#include <utility>
using namespace std;

/**
 * @class UstensilModel
 *
 * @brief the model to create the different utensils (cutlery and others)
 */
class UstensilModel {
public:
    /**
     *@brief the constructor of the utensil class
     *
     * @param name
     * @param wash_time
     */
    UstensilModel(string name, int wash_time)
        : isClean(true),
          name(name),
          washTime(wash_time) {
    }
    //to get the wash time i have to pass this comment into a docstring comment
    int getWashTime() const;
    // to change the state of the isCleand attribute
    void toogleIsClean();

private:
    bool isClean;
    string name;
    int washTime;
    // should i add a type ??

};
#endif //USTENSILMODEL_H
