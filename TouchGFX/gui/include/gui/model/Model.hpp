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
