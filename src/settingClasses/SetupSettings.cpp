#include "SetupSettings.h"

SetupSettings::SetupSettings(Heating *heating,
   CallbackFunctionPointer UpdateZC,
   CallbackFunctionPointer TrigTriac,
   SerialController *serialController,
   CallbackFunctionPointer OnRecPid,
   float *temp)
{
  this->heating = heating;
  this->UpdateZC = UpdateZC;
  this->TrigTriac = TrigTriac;
  this->OnRecPid = OnRecPid;
  this->serialController = serialController;
  this->temp = temp;
}
