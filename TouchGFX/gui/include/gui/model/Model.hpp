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

int isConnected();
int getPlug();
int shutdownClosed();
int getChargingFlag();

  int getTimeRemaining();
  int getAMS();
  int getIMD();
  int getTimeElapsed();
  int getFlag();
 int getSC2Status();
void setSCStatus(int status);
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
