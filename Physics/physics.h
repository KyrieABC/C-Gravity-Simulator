#pragma once
#include "../core/body.h"
#include <vector>

class PhysicsEngine
{
public:
    float G =  0.1f;
    void computeForces(std::vector<Body>& bodies);
    void integrate(std::vector<Body>& bodies, float dt);
    //Collision System
    void handleCollision(std::vector<Body>& bodies);
};