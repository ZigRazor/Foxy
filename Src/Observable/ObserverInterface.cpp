#include "ObserverInterface.h"
#include "ObservablePropertyInterface.h"
#include <iostream>

using namespace Foxy::Observable;

ObserverInterface::~ObserverInterface()
{
    //std::cout << "~ObserverInterface " << this << std::endl;
    //Create a copy for safe the iterator
    auto observedPropertiesCopy = observedProperties;
    for (auto observedProperty : observedPropertiesCopy)
    {
        observedProperty->deregisterObserver(this);
    }
}

void ObserverInterface::registerObservedProperty(ObservablePropertyInterface *observedProperty)
{
    //std::cout << "registerObservedProperty " << observedProperty << std::endl;
    observedProperties.insert(observedProperty);
}

void ObserverInterface::deregisterObservedProperty(ObservablePropertyInterface *observedProperty)
{
    //std::cout << "deregisterObservedProperty " << observedProperty << std::endl;
    observedProperties.erase(observedProperty);
}
