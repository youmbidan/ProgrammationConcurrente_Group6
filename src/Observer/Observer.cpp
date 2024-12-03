#ifndef OBSERVER_H
#define OBSERVER_H




#include <string>

/**
 * @class Observer
 * 
 * @brief la classe (en réalité une interface) pour les observeurs
 */

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

#endif