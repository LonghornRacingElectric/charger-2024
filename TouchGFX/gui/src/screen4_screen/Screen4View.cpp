#include <gui/screen4_screen/Screen4View.hpp>
#include "stm32u5xx_hal.h"
#include <stm32u5a9xx.h>

Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}


void Screen4View::prechargeScreen(){
    if((presenter->shutdownClosed() == 1) && (presenter->getSC2Status() == 1)){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
        //application().gotoScreen5ScreenNoTransition();
    }
    if ((presenter->shutdownClosed() == 1)){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen5ScreenNoTransition();
    }
    if (presenter->getPlug() == 0){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen3ScreenNoTransition();
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