#include "Physics/physics.h"
#include "renderer/renderer.h"

int main()
{
    std::vector<Body> bodies;
    PhysicsEngine physics;
    Renderer renderer;

    float dt = 0.01f;

    while(true)
    {
        physics.computeForces(bodies);
        physics.integrate(bodies,dt);
        physics.handleCollision(bodies);

        renderer.drawBodies(bodies);
        renderer.drawTrails(bodies);
    }
}