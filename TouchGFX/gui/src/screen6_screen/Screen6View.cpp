#include <gui/screen6_screen/Screen6View.hpp>


Screen6View::Screen6View()
{

}

void Screen6View::setupScreen()
{
    Screen6ViewBase::setupScreen();
}

void Screen6View::tearDownScreen()
{
    Screen6ViewBase::tearDownScreen();
}

void Screen6View::totalTime(){
    setTotalTime(presenter->getTimeElapsed());

}

void Screen6View::setTotalTime(int time){
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", time);
    textArea2.invalidate();
}