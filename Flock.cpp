#include "Flock.h"

Flock::Flock(int widthScreen, int heightScreen, int Size){
    this->widthScreen = widthScreen;
    this->heightScreen = heightScreen;

    for (int i = 0; i < Size; i++){
        boids.push_back(Boid(widthScreen, heightScreen, i));
    }   
}

Flock::~Flock(){}

void Flock::UpdateFlock(){
    for (int i = 0; i < boids.size(); i++){
        boids[i].DetermineDirection();
        Seperation();
        boids[i].UpdatePosition();
    }
}

void Flock::DrawFlock(Buffer& buffer){
    buffer.ClearBuffer();
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < boids.size(); i++){
        // printf("%f %f", boids[i].x, boids[i].y);
        if (boids[i].x >= 0 && boids[i].x < widthScreen && boids[i].y >= 0 && boids[i].y < heightScreen)
            buffer.UpdatePixel((int)boids[i].x, (int)boids[i].y, 8);
    }
}

//seperation
//going to run into processing time issues with this, need to seperate into chunks or multithread
void Flock::Seperation(){
    //seperate into chunks
    float avoidFactor = 0.5;

    for (auto Boid: boids){
        Boid.close_dx = 0.0;
        Boid.close_dy = 0.0;
        for (auto otherBoid: boids){
            if (Boid.id == otherBoid.id) continue;

            float distance = Boid.Distance(Boid.x, Boid.y, otherBoid.x, otherBoid.y);
            if (distance < 10){
                Boid.close_dx += (float)(Boid.x - otherBoid.x);
                Boid.close_dy += (float)(Boid.y - otherBoid.y);
            }
        }
        Boid.vx += Boid.close_dx * avoidFactor;
        Boid.vy += Boid.close_dy * avoidFactor;
    }

}

//alignment


//cohesion