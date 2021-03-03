#include "mbed.h"

DigitalIn mypin(USER_BUTTON);
DigitalOut myled(LED1);

int main()
{
    // check mypin object is initialized and connected to a pin
    if (mypin.is_connected())
    {
        printf("mypin is connected and initiallized! \n\r");
        /*
        \r’ 回車，回到當前行的行首，而不會換到下一行，如果接著輸出的話，本行以前的內容會被逐一覆蓋；
        ‘\n’ 換行，換到當前位置的下一行，而不會回到行首；
        */
    }

    // Optional: set mode as PullUp/PullDown/PullNone/OpenDrain ??
    mypin.mode(PullNone);

    // press the button and see the console / led change
    while(1)
    {
        printf("my pin has value : %d \n\r", mypin.read()); // button 按下去是 0
        myled = mypin;      // (push)mypin = 0, LED off
        ThisThread::sleep_for(250ms);
    }
}