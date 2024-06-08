#include <gui/screen3_screen/Screen3View.hpp>
#include "stm32u5xx_hal.h"
#include <stm32u5a9xx.h>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::shutdownScreen(){
    if (presenter->getPlug() == 1){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen4ScreenNoTransition();
        //application().gotoScreen4ScreenNoTransition();
    }
    if (presenter->isConnected() == 0){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
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