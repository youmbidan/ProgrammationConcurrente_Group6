#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "../../../Structs/OrderRecipe.h"

/**
 *@class Order
 *@brief Represents a client's order with associated recipes and table ID.
 */
class Order {
public:
    /**
     *@brief Constructor
     *
     * @param id Unique identifier for the order.
     * @param order_recipes Vector of recipes associated with the order.
     * @param tableId The table ID that placed the order.
     */
    Order(const std::vector<OrderRecipe*>& order_recipes, int tableId)
        : orderRecipes(order_recipes), tableId(tableId) {}

    /**
     * @brief Calculates the total cooking time for the order.
     * @return Total time in seconds.
     */
    int getTotalCookingTime() const;

    /**
     * @brief Get the table ID for the order.
     * @return Table ID.
     */
    int getTableId() const { return tableId; }


private:
    std::vector<OrderRecipe*> orderRecipes;
    int tableId;
};

#endif // ORDER_H
