#include "Buffer.h"


//constructor
Buffer::Buffer(int width, int height){
    this->width = width;
    this->height = height;

    //itialize the buffers with pixels objects
    for (int y = 0; y < height; y++){
        frontBuffer.push_back(vector<Pixel>());
        backBuffer.push_back(vector<Pixel>());
        for (int x = 0; x < width; x++){
            frontBuffer[y].push_back(Pixel());
            backBuffer[y].push_back(Pixel());
        }
    }
}

//destructor
Buffer::~Buffer(){}

void Buffer::UpdatePixel(int x, int y, int luminosity){
    backBuffer[y][x].luminosity = luminosity;
}

void Buffer::SwapBuffer(){
    swap(frontBuffer, backBuffer);
}

void Buffer::PrintBuffer(){
    char LumtoChar[] = " .,~*il#@";
    printf("\033[H");

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            printf("%c", LumtoChar[frontBuffer[y][x].luminosity]);
        }
        printf("\n");
    }
}

void Buffer::ClearBuffer(){
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            backBuffer[y][x].luminosity = 0;
        }
    }
}

void Buffer::FillBuffer(){
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            backBuffer[y][x].luminosity = 8;
        }
    }
}

void Buffer::PrintPixel(int x, int y){
    printf("%d", frontBuffer[y][x].luminosity);
}

void Buffer::PrintBufferData(){
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            printf("%d", frontBuffer[y][x].luminosity);
        }
        printf("\n");
    }
}