#ifndef FOXY_OBSERVABLE_OBSERVABLEPROPERTY
#define FOXY_OBSERVABLE_OBSERVABLEPROPERTY

#include "ObservablePropertyInterface.h"
#include "ObserverInterface.h"

namespace Foxy
{
    namespace Observable
    {
        template <typename T>
        class ObservableProperty : public ObservablePropertyInterface
        {
            public:
            ObservableProperty() = default;
            ObservableProperty(const T& value) :ObservablePropertyInterface(), m_value(value){};
            virtual ~ObservableProperty() {
                //std::cout << "~ObservableProperty " << this << std::endl;
                for( auto observer : observerSet){
                    observer->onDestroy(m_value);
                    observer->deregisterObservedProperty(this);
                }
            };
            void set(const T& value){
                T oldValue = m_value;
                m_value = value;
                std::cout << "Notify new Value " << value << std::endl;
                for( auto observer : observerSet){
                    observer->onChange(oldValue, value);
                }
            }

            const T& get() const{
                return m_value;
            }

            private:
            T m_value;
        };
    }
}


#endif //FOXY_OBSERVABLE_OBSERVABLEPROPERTY