//
// Created by franck on 12/2/24.
//

#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H


#include <iostream>
#include <vector>
#include "Recipe.h"
#include "Order.h"
#include "MobileElementModel.h"
#include <random>

using namespace std;

/**
 * @class ClientModel
 * @brief management of the different instance of the client
 *
 * the clientModel class is used to create the different instance of the client,
 * they are the one with the different methods of the client
 */
class ClientModel {
public:
    /**
     *@brief constructor of the Client class
     *
     * @param has_odered
     * @param has_ordered_entree
     * @param has_ordered_main_course
     * @param has_ordered_dessert
     */
    ClientModel(bool has_odered = false, bool has_ordered_entree = false, bool has_ordered_main_course = false,
     bool has_ordered_dessert = false)
        :
          hasOdered(has_odered),
          hasOrderedEntree(has_ordered_entree),
          hasOrderedMainCourse(has_ordered_main_course),
          hasOrderedDessert(has_ordered_dessert) {
    }

 /**
     * @brief this function is use for the client to make a choice
     *
     * @param recipes
     */

    void makeChoice(vector<Recipe> &recipes);

    /**
     * @brief change the hasOrdered state
     */
    void toogleHasOrdered();
    void toogleHasOrderedMainCourse();
    void toogleHasOrderedDessert();
    void toogleHasOrderedEntree();

    void setChoice(Recipe* choiceMade);

    Recipe* getChoice();

    /**
     * @brief client method eat
     * @param order
     */
    // void eat(Order order);

private:
    string type;
    int id;
    bool hasOdered;
    int orderTimeLeft; /** < the time left to the user to order. */
    bool hasOrderedEntree;
    bool hasOrderedMainCourse;
    bool hasOrderedDessert;
    Recipe* choice;
};



#endif //CLIENTMODEL_H
