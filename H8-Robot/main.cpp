#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHIO.h>

#define TURN_TIME 1450
#define MOTOR_SPEED 30

FEHMotor leftDriveMotor(FEHMotor::Motor0, 9);
FEHMotor rightDriveMotor(FEHMotor::Motor1, 9);
DigitalInputPin frontRightBumper(FEHIO::P1_0);
DigitalInputPin frontLeftBumper(FEHIO::P1_1);
DigitalInputPin backRightBumper(FEHIO::P2_0);
DigitalInputPin backLeftBumper(FEHIO::P2_1);



void clearScreen();
void turnLeft();
void turnRight();
void goForward();
void goBackward();
void wait();
void stopMotors();










int main(void)
{
    float x,y;
    int timer = 0;

    clearScreen();



    LCD.WriteLine("A");

    //Wait to start until screen is touched and released
    while(!LCD.Touch(&x,&y))
    {}
    while(LCD.Touch(&x,&y))
    {}

    LCD.WriteLine("B");

    //Action 1
    while(frontRightBumper.Value() && frontLeftBumper.Value())
    {
        goForward();
    }

    LCD.WriteLine("1");



    //Action 2
    while(backRightBumper.Value()) //backLeftBumper.Value() &&
    {
        turnRight();
    }

    LCD.WriteLine("2");



    //Action 3
    while(frontRightBumper.Value() && frontLeftBumper.Value())
    {
        goForward();
    }

    LCD.WriteLine("3");



    //Action 4
    while(timer < TURN_TIME)
    {
        turnLeft();
        Sleep(50);
        timer += 50;
    }

    while(backLeftBumper.Value()) // && backRightBumper.Value()
    {
        goBackward();
    }

    LCD.WriteLine("4");



    //Action 5
    while(frontRightBumper.Value() && frontLeftBumper.Value())
    {
        goForward();
    }

    LCD.WriteLine("5");

    //Do nothing afterwards
    while(true)
    {
        stopMotors();
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
    leftDriveMotor.SetPercent(MOTOR_SPEED/2);
    //leftDriveMotor.Stop();
    rightDriveMotor.SetPercent(MOTOR_SPEED);
}

void turnRight()
{
    leftDriveMotor.SetPercent(-MOTOR_SPEED);
    rightDriveMotor.Stop();
    //rightDriveMotor.SetPercent(-MOTOR_SPEED);
}

void goForward()
{
    leftDriveMotor.SetPercent(MOTOR_SPEED);
    rightDriveMotor.SetPercent(-MOTOR_SPEED);
}

void goBackward()
{
    leftDriveMotor.SetPercent(-MOTOR_SPEED);
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
