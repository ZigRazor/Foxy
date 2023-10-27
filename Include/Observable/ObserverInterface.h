#ifndef FOXY_OBSERVABLE_OBSERVERINTERFACE
#define FOXY_OBSERVABLE_OBSERVERINTERFACE

#include <any>
#include <set>

namespace Foxy
{
    namespace Observable
    {
        //Foward Declaration
        class ObservablePropertyInterface;

        class ObserverInterface
        {
        public:
            ObserverInterface() = default;
            ~ObserverInterface();
            void registerObservedProperty(ObservablePropertyInterface* observedProperty);
            void deregisterObservedProperty(ObservablePropertyInterface* observedProperty);
            virtual void onChange(std::any oldValue, std::any newValue) = 0;
            virtual void onDestroy(std::any oldValue) = 0;

        private:
            std::set<ObservablePropertyInterface*> observedProperties;
        };
    }
}


#endif //FOXY_OBSERVABLE_OBSERVERINTERFACE