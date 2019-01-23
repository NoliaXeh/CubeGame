#pragma once
#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace graphics
{
    void render_cube(double x, double y, double z);
    void render_begin();
    void render_end();
    extern SDL_Surface* win;
    void init();
}
namespace graphics::camera
{
    extern double x, y, z;
    extern double vx, vy, vz;
    extern double ax, ay, az;
}
