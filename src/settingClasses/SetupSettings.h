#ifndef __SETUPSETTINGS_H__
#define __SETUPSETTINGS_H__

#include "../FlowController/heating.h"
#include "../FlowController/SerialController.h"
#include "../Config.h"

class SetupSettings
{
  public:
      SetupSettings(Heating *heating,
      CallbackFunctionPointer UpdateZC,
      CallbackFunctionPointer TrigTriac,
      SerialController *serialController,
      CallbackFunctionPointer OnRecPid
    );

    CallbackFunctionPointer UpdateZC;
    CallbackFunctionPointer TrigTriac;
    CallbackFunctionPointer OnRecPid;
    SerialController *serialController;
    Heating *heating;

  private:

};

#endif
