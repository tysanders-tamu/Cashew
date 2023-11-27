#include "Boid.h"
#include <stdio.h>


Boid::Boid(int widthScreen, int heightScreen, int id){
    vx,vy,ax,ay, close_dx, close_dy = 0;
    vx = 1.0;
    vy = 1.0;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    x = rand() % widthScreen-10;
    y = rand() % heightScreen-10;
    this->id = id;
    this->widthScreen = widthScreen;
    this->heightScreen = heightScreen;
}

Boid::~Boid(){}

float Boid::Distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void Boid::UpdateVelocity(float influenceX, float influenceY){
    vx += ax + influenceX;
    vy += ay + influenceY;

    //limit velocity
    float speed = sqrt(vx*vx + vy*vy);
    if (speed > maxSpeed){
        vx = (vx / speed) * maxSpeed;
        vy = (vy / speed) * maxSpeed;
    } else if (speed < minSpeed){
        vx = (vx / speed) * minSpeed;
        vy = (vy / speed) * minSpeed;
    }
}

void Boid::UpdatePosition(){
    x += vx;
    y += vy;
}

//determine distance to any obstacle
void Boid::DetermineDirection(){
    //if outside of bounds
    if (x <= -5 || x >= widthScreen+5 || y <= -5 || y >= heightScreen+5){
        vx = -vx;
        vy = -vy;
    } else {
        srand(chrono::high_resolution_clock::now().time_since_epoch().count());
        float rotationAngle = rand()%10;
        rotationAngle = rotationAngle * 3.141 / 180;
        
        rotationAngle *= rand() % 2 == 0 ? 1 : -1; //left or right
        
        float _vy = vy;
        float _vx = vx;

        vx = _vx * cos(rotationAngle) - _vy * sin(rotationAngle);
        vy = _vx * sin(rotationAngle) + _vy * cos(rotationAngle);
    }
}
 