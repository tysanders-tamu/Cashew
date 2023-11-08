#ifndef FLOCK_H
#define FLOCK_H

#include <vector>
#include "Boid.h"
#include "Buffer.h"

using namespace std;

class Flock {
    public:
        Flock(int widthScreen, int heightScreen, int Size);
        ~Flock();
        void UpdateFlock();
        void DrawFlock(Buffer& buffer);
        void Seperation();
    private:
        vector<Boid> boids;
        int widthScreen, heightScreen;
};

#endif // Flock