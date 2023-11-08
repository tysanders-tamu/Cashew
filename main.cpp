#include <iostream>
#include "Buffer.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include "Flock.h"

//calculate force on object

//vector of the objects

//object


int main(int argc, char const *argv[])
{

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);



    Buffer* mainBuffer = new Buffer(w.ws_col, w.ws_row-1);
    Flock flock(w.ws_col, w.ws_row-2, 100);

    for(;;){
    // {
        flock.UpdateFlock();
        flock.DrawFlock(*mainBuffer);
        mainBuffer->SwapBuffer();
        mainBuffer->PrintBuffer();
        usleep(0.002*10000000);
    }

    
    return 0;
}
