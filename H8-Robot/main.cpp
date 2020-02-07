#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#define TURN_TIME 2
#define MOTOR_SPEED 30

FEHMotor leftDriveMotor(FEHMotor::Motor0);
FEHMotor rightDriveMotor(FEHMotor::Motor1);
DigitalInputPin frontRightBumper(FEHIO::P1_0);
DigitalInputPin frontLeftBumper(FEHIO::P1_1);
DigitalInputPin backRightBumper(FEHIO::P2_0);
DigitalInputPin backLeftBumper(FEHIO::P2_1);



void clearScreen();
void turnLeft();
void turnRight();
void goStraight();
void wait();
void stopMotors();










int main(void)
{
    float x,y;




    //Wait to start until screen is touched and released
    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}



    //Action 1
    while(!frontRightBumper.Value() && !frontLeftBumper.Value())
    {
        goStraight();
    }




    return 0;
}










void clearScreen()
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);
}

void turnLeft()
{
    leftDriveMotor.SetPercent(-MOTOR_SPEED);
    rightDriveMotor.SetPercent(MOTOR_SPEED);
}

void turnRight()
{
    leftDriveMotor.SetPercent(MOTOR_SPEED);
    rightDriveMotor.SetPercent(-MOTOR_SPEED);
}

void goStraight()
{
    leftDriveMotor.SetPercent(MOTOR_SPEED);
    rightDriveMotor.SetPercent(MOTOR_SPEED);
}

void wait()
{
    Sleep(0.5);
}

void stopMotors()
{
    leftDriveMotor.Stop();
    rightDriveMotor.Stop();
}
