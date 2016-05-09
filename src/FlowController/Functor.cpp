#include "SerialController.h"

class Functor {
    SerialController * instance;
  public:
    Functor(SerialController * instance) : instance(instance) {
    }
    void operator()() {
        //instance->OnReceivePid();
    }
};
