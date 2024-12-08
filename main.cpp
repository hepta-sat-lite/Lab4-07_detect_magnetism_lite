#include "mbed.h"
#include "LITE_EPS.h"
#include "LITE_SENSOR.h"
LITE_EPS eps(PA_0,PA_4);
LITE_SENSOR sensor(PA_7,PB_7,PB_6);
RawSerial pc(USBTX,USBRX,9600);
int main()
{   
    float mx,my,mz;
    eps.turn_on_regulator(); //Turn on 3.3V converter
    sensor.set_up();
    for(int i=0;i<50;i++){
        sensor.sen_mag(&mx,&my,&mz);
        pc.printf("mag : %f,%f,%f\r\n",mx,my,mz);
        wait_ms(1000);
    }
}