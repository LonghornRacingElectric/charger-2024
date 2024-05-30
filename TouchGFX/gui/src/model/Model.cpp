#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <fdcan.h>
#include <stdint.h>
#endif

int counter = 0;
int longCounter = 0;
float stateofcharge = 0;
int plugFlag = 0;
uint16_t shutdownFlag = 0;
uint16_t prechargingFlag = 0;
uint16_t chargingFlag = 0;
uint16_t timeRemaining = 0;
int amsFlag = 0;
int imdFlag = 0;
uint16_t packVoltage = 0;
uint16_t initialTime = 65535;

Model::Model() : modelListener(0), outputVoltage(252.0f), outputCurrent(10.0f), faultVector(0x80)
{

}

#ifndef SIMULATOR
void Model::receivePacket() {
  static FDCAN_RxHeaderTypeDef RxHeader;
  static uint8_t RxData[8];
  static bool started = false;
  static uint32_t err;

  static uint8_t data[8];
  if(!started) {
    err = HAL_FDCAN_Start(&hfdcan1);
    started = true;
    plugFlag = 1;
    return;
  }


  //uint32_t fillLevel = HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0);
  err = HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData);
  if(err) {
    // outputVoltage = -6.0f;
    // while (err) {
    //   err >>= 1;
    //   outputVoltage += 6.0f;
   // }
  } else {
    uint32_t id = RxHeader.Identifier;
    //outputVoltage = fillLevel * 6.0f; //450.0f;
    faultVector = 0;
    if(id == 0x18FF50E5) {
     outputVoltage = static_cast<float>((RxData[0] << 8) | RxData[1]) * 0.1f;
     outputCurrent = static_cast<float>((RxData[2] << 8) | RxData[3]) * 0.1f;
     faultVector = RxData[4];
    }
    if (id == 0x420){
      uint16_t flags = *((uint16_t*)&data[0]);
      shutdownFlag = (flags>>4) & 1;
      prechargingFlag = (flags>>3) & 1;
      chargingFlag = (flags>>2)&1;
      amsFlag = (flags>>1)&1;
      imdFlag = (flags)&1;
      packVoltage = static_cast<float>(*((uint16_t*)&data[2])) * 0.1f;
      stateofcharge = static_cast<float>(*((uint16_t*)&data[4])) * 0.1f;
      timeRemaining = *((uint16_t*)&data[6]);
      if (initialTime>timeRemaining){
        initialTime = timeRemaining;
      }
    }

  }
}

void Model::sendPacket() {
  static FDCAN_TxHeaderTypeDef TxHeader;
  TxHeader.Identifier = 0x1806E5F4;
  TxHeader.IdType = FDCAN_EXTENDED_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = FDCAN_DLC_BYTES_8;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0;

  float requestVoltage = 480.0f;
  float requestCurrent = 1.5f;
  unsigned int control = 1;

  uint16_t voltageInt = static_cast<int>(requestVoltage * 10.0f);
  uint16_t currentInt = static_cast<int>(requestCurrent * 10.0f);
if(longCounter <=180){
  longCounter++;
}
else{
  //control = 0;
  
}
  static uint8_t TxData[8];
  TxData[0] = voltageInt >> 8;
  TxData[1] = voltageInt & 0xFF;
  TxData[2] = currentInt >> 8;
  TxData[3] = currentInt & 0xFF;
  TxData[4] = control;

counter++;
if (counter == 60){
  int err = HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);
  if(err) {
    HAL_FDCAN_AbortTxRequest(&hfdcan1, 0xFFFFFFFF);
  }
  counter = 0;
}
}
#endif

void Model::tick()
{
#ifdef SIMULATOR
  outputVoltage += 0.1f;
  if(outputVoltage > 600.0f) {
    outputVoltage = 0.0f;
  }
#endif
#ifndef SIMULATOR
  receivePacket();
  //sendPacket();
#endif
}

float Model::getSoC() {
  return stateofcharge;
}

bool Model::getState() {
  return !faultVector;
}

float Model::getVolts(){
  //return outputVoltage;
  return packVoltage;
}

float Model::getCurr(){
  return outputCurrent;
}

int Model::getPlug(){
  return plugFlag;
}

int Model::getShutdownFlag(){
  return shutdownFlag;
}

int Model::getPrechargingFlag(){
  return prechargingFlag;
}

int Model::getChargingFlag(){
  return chargingFlag;
}

int Model::getTimeRemaining(){
  return timeRemaining;
}

int Model::getAMS(){
  return 1;
  //return amsFlag;
}

int Model::getIMD(){
  return 1;
  //return imdFlag;
}

int Model::getTimeElapsed(){
  return initialTime;
}