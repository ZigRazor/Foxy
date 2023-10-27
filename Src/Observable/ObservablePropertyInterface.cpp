#include "ObservablePropertyInterface.h"
#include "ObserverInterface.h"
#include <iostream>

using namespace Foxy::Observable;

void ObservablePropertyInterface::registerObserver(ObserverInterface *observer)
{
    //std::cout << "registerObeserver " <<  observer << std::endl;
    observerSet.insert(observer);
    observer->registerObservedProperty(this);
}

void ObservablePropertyInterface::deregisterObserver(ObserverInterface *observer)
{
    //std::cout << "deregisterObeserver " <<  observer << std::endl;
    observerSet.erase(observer);
    observer->deregisterObservedProperty(this);
}
