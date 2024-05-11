#include <gui/screen1_screen/Screen1View.hpp>

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
}

void Screen1View::setCharge(int charge) {
  battProgress.setValue(charge);
  textProgress1.setValue(charge);
}

void Screen1View::setState(bool state) {
//  idleText.setVisible(false);
//  chargingText.setVisible(true);
}
