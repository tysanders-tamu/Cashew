struct Pixel
{
    int luminosity = 0;
};



#include <vector>
#include <iostream>
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

    void UpdatePixel(int x, int y, int luminosity){
        backBuffer[y][x].luminosity = luminosity;
    }

    void SwapBuffer(){
        frontBuffer = backBuffer;
    }

    void PrintBuffer(){
        enum char* lumToken {"a","@","B","%","8","&","W","M","#","*","o","a","h","k","b","d","p","q","w","m","Z","O","0","Q","L","C","J","U","Y","X","z","c","v","u","n","x","r","j","f","t","/","\\","|","(",")","1","{","}","[","]","?","-","_","+","~","<",">","i","!","l","I",";",":",",","\"","^","`","'","."};
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                printf("%d", frontBuffer[y][x].luminosity)
            }
            cout << endl;
        }
    }
};