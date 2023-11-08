#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <iostream>
#include "Pixel.h"

using namespace std;

class Buffer {
public:
    Buffer(int width, int height);
    ~Buffer();
    void UpdatePixel(int x, int y, int luminosity);
    void SwapBuffer();
    void PrintBuffer();
    void ClearBuffer();
    void FillBuffer();
    void PrintPixel(int x, int y);
    void PrintBufferData();
public:
    int width, height;
private:
    vector<vector<Pixel>> frontBuffer;
    vector<vector<Pixel>> backBuffer;
};

#endif // BUFFER_H