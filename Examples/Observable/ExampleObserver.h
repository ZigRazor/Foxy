#include "ObserverInterface.h"

class ExampleObserver : public Foxy::Observable::ObserverInterface {
    public:
    ExampleObserver() = default;
    virtual ~ExampleObserver() = default;

    void onChange(std::any oldValue, std::any newValue) override;
    void onDestroy(std::any oldValue) override;
};