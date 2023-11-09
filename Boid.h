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
    void UpdateVelocity(float influenceX = 0, float influenceY = 0);
    void UpdatePosition();
    void DetermineDirection();

public:
    float close_dx, close_dy;
    float x_posAvg, y_posAvg;
    float x_velAvg, y_velAvg;
    int neighbors;
    float x, y;
    float vx, vy;
    float ax, ay;
    int id;
private:
    int widthScreen;
    int heightScreen;
    float maxSpeed = 2.5;
    float minSpeed = .5;
};

#endif // BOID_H