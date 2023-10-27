#include "ExampleObserver.h"
#include "iostream"

void ExampleObserver::onChange(std::any oldValue, std::any newValue)
{
    int intOldValue = std::any_cast<int>(oldValue);
    int intNewValue = std::any_cast<int>(newValue);

    std::cout << "Old Value: " << intOldValue << " New Value: " << intNewValue << std::endl;

}

void ExampleObserver::onDestroy(std::any oldValue)
{
    int intOldValue = std::any_cast<int>(oldValue);
    std::cout << "Old Value: " << intOldValue << " of destroyed object" << std::endl;
}
