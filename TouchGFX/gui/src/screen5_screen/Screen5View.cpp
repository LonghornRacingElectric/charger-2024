#include <gui/screen5_screen/Screen5View.hpp>

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
}