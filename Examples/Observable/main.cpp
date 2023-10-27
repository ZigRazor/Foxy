#include <iostream>
#include "ObservableProperty.hpp"
#include "ExampleObserver.h"

using namespace Foxy::Observable;

int main(){
    std::cout << "Observable Example" << std::endl;
    ObservableProperty<int> intProp1;
    
    ExampleObserver observer1;
    {
    ExampleObserver observer2;
    ObservableProperty<int> intProp2;
    intProp1.registerObserver(&observer1);
    intProp1.registerObserver(&observer2);
    intProp2.registerObserver(&observer1);
    intProp1.set(10);
    intProp2.set(29);
    }
    intProp1.set(44);

 
    return 0;
}