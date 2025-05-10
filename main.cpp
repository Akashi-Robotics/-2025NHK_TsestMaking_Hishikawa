#include "DigitalOut.h"
#include "PinNamesTypes.h"
#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
    PwmOut servo(PC_8);
    DigitalOut lim(PB_7, PullDown);

    servo.period_us(5096);

    servo.pulsewidth_us(500);
    bool flag = true;



    while(true){
        wait_ms(50);
        if (!lim.read() && flag){
            servo.pulsewidth_us(1500);
            flag =false;
            printf("h");
        }
        printf("%d\n",!lim.read());
    }
}
