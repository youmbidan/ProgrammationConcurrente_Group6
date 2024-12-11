#include "Observer.h"

#include <vector>

class Observable
{
public:
    virtual ~Observable() = default;
    virtual void subscribe(Observer *observer);
    virtual void unsubscribe(Observer *observer);
    virtual void notify(const std::any& data);

private:
    std::vector<Observer *> observers;
};
