#include <gui/screen3_screen/Screen3View.hpp>

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
    if (presenter->getShutdown() == 1){
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen4ScreenNoTransition();
        //application().gotoScreen4ScreenNoTransition();
    }
}