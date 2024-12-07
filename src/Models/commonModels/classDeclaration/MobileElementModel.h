//
// Created by franck on 12/2/24.
//

#ifndef MobileElementModel_H
#define MobileElementModel_H

/**
 * @class MobileElementModel
 *
 * @brief this class regroup all MobileElementModels of the structure
 */
class MobileElementModel {
public:
    /**
     *@brief constructor of the MobileElementModel class
     *
     * @param abscice
     * @param intercept
     */
    MobileElementModel(double abscice, double intercept)
        : abscice(abscice),
          intercept(intercept) {
    }
    /**
     * @brief this function mave move the differents MobileElementModel with a pathfinding algorithm
     */
    void move();

private:
    double abscice;/** <L'abscice de chaque humain à un instant T */
    double intercept;/** <L'ordonnée de chaque humain à un instant T */

};
#endif //MobileElementModel_H
