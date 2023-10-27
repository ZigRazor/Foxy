#ifndef FOXY_OBSERVABLE_OBSERVABLEPROPERTYINTERFACE
#define FOXY_OBSERVABLE_OBSERVABLEPROPERTYINTERFACE

#include <set>

namespace Foxy
{
    namespace Observable
    {

        //Foward Declaration
        class ObserverInterface;

        class ObservablePropertyInterface
        {
            public:
                ObservablePropertyInterface() = default;
                virtual ~ObservablePropertyInterface() = default;    

                void registerObserver(ObserverInterface* observer);
                void deregisterObserver(ObserverInterface* observer);

            protected:
                std::set<ObserverInterface*> observerSet;
        };
    }
}


#endif //FOXY_OBSERVABLE_OBSERVABLEPROPERTYINTERFACE