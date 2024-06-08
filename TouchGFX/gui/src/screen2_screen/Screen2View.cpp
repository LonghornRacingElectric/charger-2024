#include <gui/screen2_screen/Screen2View.hpp>


Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::plugScreen(){
    if(presenter->getPlugFlag() == 1){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen3ScreenNoTransition();
        //application().FrontendApplicationBase::gotoScreen3ScreenNoTransition();
    }

     // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
     //   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);

    //  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);


}