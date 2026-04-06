# pragma once
#include "../core/body.h"
#include <vector>

class Renderer
{
public:
    void drawBodies(const std::vector<Body>& bodies);
    void drawTrails(const std::vector<Body>& bodies);
};