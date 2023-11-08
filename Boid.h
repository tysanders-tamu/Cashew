#ifndef BOID_H
#define BOID_H

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

class Boid {
public:
    float Distance(float x1, float y1, float x2, float y2);
    Boid(int widthScreen, int heightScreen, int id);
    ~Boid();
    void UpdateVelocity();
    void UpdatePosition();
    void DetermineDirection();

public:
    float close_dx, close_dy;
    float x, y;
    float vx, vy;
    float ax, ay;
    int id;
private:
    int widthScreen;
    int heightScreen;
};

#endif // BOID_H