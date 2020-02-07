#include <FEHLCD.h>
#include <FEHUtility.h>

int main(void)
{
    float x,y;

    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);

    while(true)
    {
        if(LCD.Touch(&x,&y))
        {
            LCD.WriteLine("Hello World!");
            Sleep(100);
        }
    }

    return 0;
}
