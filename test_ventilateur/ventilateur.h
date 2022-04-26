#ifndef Ventilateur
#define Ventilateur

#define PORT 13     //  OUTPUT D7 (GPIO13) --> FAN
#define Pushbutton 12 // INPUT D5(GPIO14) --> Push Button

//#include <iostream>
using namespace std;


class ventilateur
{
  private:
    bool pushbutton;
    
  public:
    ventilateur();
   ~ventilateur();

    void startMotor(); 
    void setspeedPWM(int pwm);
    void stopMotor();
};

#endif
