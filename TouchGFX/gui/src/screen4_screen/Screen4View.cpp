#include <gui/screen4_screen/Screen4View.hpp>

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
    if(presenter->getPrechargeFlag() == 1){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen5ScreenNoTransition();
        //application().gotoScreen5ScreenNoTransition();
    }
}