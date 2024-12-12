//
// Created by franck on 12/2/24.
//

#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "Recipe.h"
#include "../../../Structs/OrderRecipe.h"

using namespace std;

/**
 *@class Order
 *@brief the Order class is used to save the differents order of the clients
 */
class Order {
public:
    /**
     *@brief Order class constructor
     *
     * @param order_recipes
     * @param id
     * @param client
     */
    Order(const vector<OrderRecipe*> order_recipes, int tableId)
        : orderRecipes(order_recipes),
          tableId(tableId)
          {
    }

    /**
     * @brief this method create cutlery for the current order
     *
     */
    void CreateCutlery();

private:
    // declare a table attribute type : table
    vector<OrderRecipe*> orderRecipes;
    int tableId;
    int id;

};
#endif //ORDER_H
