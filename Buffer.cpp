struct Pixel
{
    int luminosity = 0;
};



#include <vector>
using namespace std;

class Buffer{
    private:
        vector<vector<Pixel>> frontBuffer;
        vector<vector<Pixel>> backBuffer;

    public:
        int width, height;

    Buffer(int width, int height){
        this->width = width;
        this->height = height;

        //itialize the buffers with pixels objects
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                frontBuffer[y][x] = Pixel();
                backBuffer[y][x] = Pixel();
            }
        }
    }

    void UpdatePixel(int x, int y){
        backBuffer[y][x]
    }

    void SwapBuffer(){
        frontBuffer = backBuffer;
    }
};