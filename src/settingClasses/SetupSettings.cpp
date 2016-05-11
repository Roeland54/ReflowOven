#include "SetupSettings.h"

SetupSettings::SetupSettings(Heating *heating,
   CallbackFunctionPointer UpdateZC,
   CallbackFunctionPointer TrigTriac,
   SerialController *serialController,
   CallbackFunctionPointer OnRecPid)
{
  this->heating = heating;
  this->UpdateZC = UpdateZC;
  this->TrigTriac = TrigTriac;
  this->OnRecPid = OnRecPid;
  this->serialController = serialController;
}
