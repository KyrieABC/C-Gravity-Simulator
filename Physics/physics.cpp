#include "physics.h"
#include <glm/glm.hpp>
#include "../Utility/Integrator.h"
void PhysicsEngine::computeForces(std::vector<Body>& bodies)
{
    //Set initial acceleration
    for (auto& b:bodies) {b.acceleration = glm::vec3(0);}
    
    for(int i = 0; i < bodies.size(); i++)
    {
        for(int j = i + 1; j < bodies.size(); j++)
        {

            //Vector direction (3d vector)
            glm::vec3 dir = bodies[j].position - bodies[i].position;
            float dist = glm::length(dir) + 0.01f;

            //F = G*M(1)M(2)/r^2
            float force = G * bodies[i].mass * bodies[j].mass / (dist * dist);
            
            //Force Vector = directional vector * force 
            glm::vec3 acc = glm::normalize(dir) * force;

            bodies[i].acceleration += acc / bodies[i].mass;
        }
    }
}

void PhysicsEngine::integrate(std::vector<Body>& bodies, float dt)
{
    for(auto& b : bodies)
    {
        verlet(b,dt);
    }
}

//Handles Collision
void PhysicsEngine::handleCollision(std::vector<Body>& bodies)
{
    for(int i = 0; i < bodies.size(); i++)
    {
        for(int j =i; j < bodies.size(); j++)
        {
            float dist = glm::length(bodies[i].position - bodies[j].position);
            if (dist < 0.05f) // Collision threshold
            {
                bodies[i].mass += bodies[j].mass;
                bodies[j].mass = 0;
            }
        }
    }
}