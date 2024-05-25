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
  setVoltage(presenter->getVoltss());
  setCurrent(presenter->getCurrent());
  setTime(presenter->getTime());
}

void Screen1View::setCharge(int charge) {
  battProgress.setValue(charge);
  textProgress1.setValue(charge);
}

void Screen1View::setState(bool state) {
  idleText.setVisible(false);
  chargingText.setVisible(true);
}

void Screen1View::setVoltage(int voltage){
  Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",voltage);
  textProgress2.setValue(voltage);
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