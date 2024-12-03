#include "Observer.cpp"
 
class Observable {
public:
    virtual ~Observable() = default;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
};
