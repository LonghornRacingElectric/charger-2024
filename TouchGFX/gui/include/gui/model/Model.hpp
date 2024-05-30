#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    float getSoC();
  bool getState();
  float getVolts();
  float getCurr();
  int getPlug();
  int getShutdownFlag();
  int getPrechargingFlag();
  int getChargingFlag();
  int getTimeRemaining();
  int getAMS();
  int getIMD();
  int getTimeElapsed();
protected:
    ModelListener* modelListener;
  float outputVoltage;
  float outputCurrent;
  unsigned int faultVector;

#ifndef SIMULATOR
  void receivePacket();
  void sendPacket();
#endif
};

#endif // MODEL_HPP
