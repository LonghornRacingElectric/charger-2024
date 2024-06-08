#include <gui/screen5_screen/Screen5View.hpp>
#include "stm32u5xx_hal.h"
#include <stm32u5a9xx.h>

Screen5View::Screen5View()
{

}

void Screen5View::setupScreen()
{
    Screen5ViewBase::setupScreen();
}

void Screen5View::tearDownScreen()
{
    Screen5ViewBase::tearDownScreen();
}

void Screen5View::chargingScreen(){
    if (presenter->getChargeFlag() == 1){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();
        //application().gotoScreen1ScreenNoTransition();
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