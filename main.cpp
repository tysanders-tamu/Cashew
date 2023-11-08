#include <iostream>
#include "Buffer.h"
#include <unistd.h>
#include <sys/ioctl.h>

//calculate force on object

//vector of the objects

//object


int main(int argc, char const *argv[])
{

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    Buffer* mainBuffer = new Buffer(w.ws_col, w.ws_row-1);

    //how long each frame "is"
    int velocity = 0;
    int deltaDistance = 0;
    int frameCount = 0;
    int ycoord = 1;
    int gravity = 9.81/9;
    int energyLoss = 0.9;
    int maxFloorTime = 30;
    int FloorTime = 0;
    for(;;){
        frameCount++;
        mainBuffer->ClearBuffer();
        mainBuffer->UpdatePixel(w.ws_col/2, ycoord, 8);
        mainBuffer->SwapBuffer();
        mainBuffer->PrintBuffer();
        //wrap around
        velocity = gravity*frameCount + velocity;
        deltaDistance = velocity; //velocity*time(1 frame)


        if (deltaDistance + ycoord >= w.ws_row-1){
            ycoord = w.ws_row-2;
            frameCount = 0;
            velocity = -velocity;
            velocity *= 0.5;
        } else {
            ycoord += deltaDistance;
        }

        if (velocity <= abs(10)){
            FloorTime++;
        }
        if (FloorTime == maxFloorTime){
            ycoord = 1;
            FloorTime = 0;
            velocity = 0;
        }

        usleep(0.11*1000000);
        printf("%d", velocity);
    }
    return 0;
}
