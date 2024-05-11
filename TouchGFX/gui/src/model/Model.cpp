#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <fdcan.h>
#include <stdint.h>
#endif


Model::Model() : modelListener(0), outputVoltage(252.0f), outputCurrent(10.0f), faultVector(0x80)
{

}

#ifndef SIMULATOR
void Model::receivePacket() {
  static FDCAN_RxHeaderTypeDef RxHeader;
  static uint8_t RxData[8];
  static bool started = false;
  static uint32_t err;

  if(!started) {
    err = HAL_FDCAN_Start(&hfdcan1);
    started = true;
    return;
  }


  uint32_t fillLevel = HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0);
//  uint32_t err = HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData);
  if(err) {
    outputVoltage = -6.0f;
    while (err) {
      err >>= 1;
      outputVoltage += 6.0f;
    }
  } else {
    uint32_t id = RxHeader.Identifier;
    outputVoltage = fillLevel * 6.0f; //450.0f;
    faultVector = 0;
    if(id == 0x18FF50E5) {
//      outputVoltage = static_cast<float>((RxData[0] << 8) | RxData[1]) * 0.1f;
//      outputCurrent = static_cast<float>((RxData[2] << 8) | RxData[3]) * 0.1f;
//      faultVector = RxData[4];
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

  float requestVoltage = 570.0f;
  float requestCurrent = 10.0f;
  unsigned int control = 1;

  uint16_t voltageInt = static_cast<int>(requestVoltage * 10.0f);
  uint16_t currentInt = static_cast<int>(requestCurrent * 10.0f);

  static uint8_t TxData[8];
  TxData[0] = voltageInt >> 8;
  TxData[1] = voltageInt & 0xFF;
  TxData[2] = currentInt >> 8;
  TxData[3] = currentInt & 0xFF;
  TxData[4] = control;

  int err = HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData);
  if(err) {
    HAL_FDCAN_AbortTxRequest(&hfdcan1, 0xFFFFFFFF);
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
  sendPacket();
#endif
}

float Model::getSoC() {
  return outputVoltage/6.0f;
}

bool Model::getState() {
  return !faultVector;
}

