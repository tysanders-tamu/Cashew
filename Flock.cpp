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
        boids[i].UpdateVelocity();
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
    // float avoidFactor = 0.0006;
    // float centerFactor = 0.008;
    // float alignFactor = 0.0006;
    float avoidFactor = 0.0006;
    float centerFactor = 0.000008;
    float alignFactor = 0.0006;

    for (auto& Boid: boids){
        Boid.close_dx = 0;
        Boid.close_dy = 0;
        Boid.x_posAvg = 0;
        Boid.y_posAvg = 0;
        Boid.neighbors = 0;
        Boid.x_velAvg, Boid.y_velAvg = 0;
        for (auto& otherBoid: boids){
            if (Boid.id == otherBoid.id) continue;

            //seperation
            float distance = Boid.Distance(Boid.x, Boid.y, otherBoid.x, otherBoid.y);
            if (distance < 2){
                Boid.close_dx += (Boid.x - otherBoid.x);
                Boid.close_dy += (Boid.y - otherBoid.y);
            }
            if (distance < 1){
                Boid.close_dx += (Boid.x - otherBoid.x);
                Boid.close_dy += (Boid.y - otherBoid.y);
            }

            if (distance < 15){
                Boid.x_posAvg += otherBoid.x;
                Boid.y_posAvg += otherBoid.y;
                Boid.x_velAvg += otherBoid.vx;
                Boid.y_velAvg += otherBoid.vy;
                Boid.neighbors++;
            }

        }
        //back to boid
        Boid.vx += Boid.close_dx * avoidFactor;
        Boid.vy += Boid.close_dy * avoidFactor;

        //cohesion
        if (Boid.neighbors > 0){
            Boid.x_posAvg /= Boid.neighbors;
            Boid.y_posAvg /= Boid.neighbors;

            Boid.x_velAvg /= Boid.neighbors;
            Boid.y_velAvg /= Boid.neighbors;

            Boid.vx += (Boid.x_posAvg - Boid.x) * centerFactor;
            Boid.vy += (Boid.y_posAvg - Boid.y) * centerFactor;

            Boid.vx += (Boid.x_velAvg - Boid.vx) * alignFactor;
            Boid.vy += (Boid.y_velAvg - Boid.vy) * alignFactor;
        }

        // Boid.UpdateVelocity(Boid.close_dx * avoidFactor, Boid.close_dy * avoidFactor);
    }

}

//alignment