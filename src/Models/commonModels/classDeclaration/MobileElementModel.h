//
// Created by franck on 12/2/24.
//

#ifndef MobileElementModel_H
#define MobileElementModel_H
#include <QTimer>
#include <QThread>
#include "../../../Structs/PointStruct.h"
#include <iostream>
#include "../../../Observer/Observable.h"

/**
 * @class MobileElementModel
 *
 * @brief this class regroup all MobileElementModels of the structure
 */
class MobileElementModel : public QObject, public Observable {
    
public:
    /**
     *@brief constructor of the MobileElementModel class
     *
     * @param abscice
     * @param intercept
     */
    MobileElementModel(double abscice, double intercept, QObject* parent = nullptr)
        :   QObject(parent),
            abscice(abscice),
            intercept(intercept),
            initialAbscice(abscice),
            initialIntercept(intercept){
    }

    /**
     * @brief this function mave move the differents MobileElementModel with a pathfinding algorithm
     *
     * @param finalX
     * @param finalY
     */
    void move(PointStruct finalCoords);
    void backToInitialPosition();

private:
    double abscice;/** <L'abscice de chaque humain à un instant T */
    double intercept;/** <L'ordonnée de chaque humain à un instant T */
    double initialAbscice;
    double initialIntercept;


};
#endif //MobileElementModel_H
