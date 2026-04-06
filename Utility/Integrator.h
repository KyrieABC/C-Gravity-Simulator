# pragma once
#include "../core/body.h"

inline void verlet(Body& b, float dt)
{
    //X(f) = X(i) + V(i) * t + 1/2*a*t^2
    glm::vec3 newPos = b.position + b.velocity * dt + 0.5f * b.acceleration * dt * dt;
    glm::vec3 newVel = b.velocity + b.acceleration * dt;

    b.position = newPos;
    b.velocity = newVel;

    b.trail.push_back(b.position);
}