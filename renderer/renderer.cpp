#include "renderer.h"
#include <GL/gl.h>

void Renderer::drawBodies(const std::vector<Body>& bodies)
{
    for (const auto& b : bodies)
    {
        glPointSize(5.0f);
        glBegin(GL_POINTS);
        glVertex3f(b.position.x, b.position.y, b.position.z);
        glEnd();
    }
}

void Renderer::drawTrails(const std::vector<Body>& bodies)
{
    for (const auto& b: bodies)
    {
        glBegin(GL_LINE_STRIP);
        for (auto& p : b.trail) glVertex3f(p.x, p.y, p.z);
        glEnd();
    }
}