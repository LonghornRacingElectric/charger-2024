#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32u5xx_hal.h"
#include <stm32u5a9xx.h>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::bababooey() {
  setCharge(presenter->getCharge());
  setState(presenter->getState());
  setVoltage(presenter->getVoltss());
  setCurrent(presenter->getCurrent());
  setTime(presenter->getTime());
  if (presenter->getTime() == 0){
    static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen6ScreenNoTransition();
    application().gotoScreen6ScreenNoTransition();
  }
  if (presenter->getAMS() == 1){
         HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

  }
  else{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

  }
  if (presenter->getIMD() == 1){
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  }
  else{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  }
}



void Screen1View::setCharge(int charge) {
  battProgress.setValue(charge);
  textProgress1.setValue(charge);
}

void Screen1View::setState(bool state) {
//  idleText.setVisible(false);
//  chargingText.setVisible(true);
}

void Screen1View::setVoltage(int voltage){
  Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",voltage);
//  textProgress2.setValue(voltage);
  textArea1.invalidate();
}

void Screen1View::setCurrent(int current){
  Unicode::snprintf(textArea2Buffer, TEXTAREA1_SIZE, "%d",current);
  textArea2.invalidate();
}

void Screen1View::setTime(int time){
  Unicode::snprintf(textArea3Buffer, TEXTAREA1_SIZE, "%d", time);
  textArea3.invalidate();
}