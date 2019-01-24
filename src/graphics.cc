#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "graphics.hh"
#include <cstdlib>

namespace graphics::camera
{
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
}
namespace graphics
{

    void render_cube(double x, double y, double z, int id)
    {
        switch (id)
        {
        case 1:
            render_cube(x, y, z, 120, 250, 140);
            break;
        case 2:
            render_cube(x, y, z, 120, 120, 140);
            break;
        case 3:
            render_top(x, y, z, 80, 80, 255, 30);
            break;
        default:
            break;
        }
    }
    void render_cube(double x, double y, double z)
    {
        render_cube(x, y, z, 1);
    }
    void render_top(double x, double y, double z, int r, int g, int b, int a)
    {
        glBegin(GL_QUADS);
        double s = 1;
        s /= 2;
        double l = 0.7;
        /*
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x + s, y + s, z + s); // + + +
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x - s, y + s, z - s); // - + -
        glVertex3d(x - s, y + s, z + s); // - + +
        l = 0.6;
        */
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x + s, y - s, z + s); // + - +
        glVertex3d(x + s, y - s, z - s); // + - -
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x + s, y + s, z + s); // + + +
        l = 0.7;
        glEnd();
    }
    void render_cube(double x, double y, double z, int r, int g, int b, int a)
    {
        glBegin(GL_QUADS);
        double s = 1;
        s /= 2;
        double d = 0;
        double l = 0.7 + d;
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x + s, y + s, z + s); // + + +
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x - s, y + s, z - s); // - + -
        glVertex3d(x - s, y + s, z + s); // - + +
        l = 0.6 + d;
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x + s, y - s, z + s); // + - +
        glVertex3d(x + s, y - s, z - s); // + - -
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x + s, y + s, z + s); // + + +
        l = 0.7 + d;
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x - s, y - s, z + s); // - - +
        glVertex3d(x - s, y - s, z - s); // - - -
        glVertex3d(x + s, y - s, z - s); // + - -
        glVertex3d(x + s, y - s, z + s); // + - +
        l = 0.6 + d;
        //back
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x - s, y - s, z + s);
        glVertex3d(x - s, y - s, z - s);
        glVertex3d(x - s, y + s, z - s);
        glVertex3d(x - s, y + s, z + s);
        l = 0.9 + d;
        //up
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x - s, y - s, z + s);
        glVertex3d(x - s, y + s, z + s);
        glVertex3d(x + s, y + s, z + s);
        glVertex3d(x + s, y - s, z + s);
        l = 0.3 + d;
        //down
        glColor4ub((int)(r * l), (int)(g * l), (int)(b * l), a);
        glVertex3d(x - s, y - s, z - s);
        glVertex3d(x - s, y + s, z - s);
        glVertex3d(x + s, y + s, z - s);
        glVertex3d(x + s, y - s, z - s);
        glEnd();
        if (0)
        {
            glLineWidth(1.0f);
            glBegin(GL_LINES);
            l = 0.2;
            glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
            //glColor3ub(255, 0, 0);
            glVertex3d(x - s, y - s, z + s);
            glVertex3d(x + s, y - s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y + s, z + s);
            glVertex3d(x + s, y - s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y + s, z + s);
            glVertex3d(x - s, y + s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x - s, y - s, z + s);
            glVertex3d(x - s, y + s, z + s);
            glEnd();
            glBegin(GL_LINES);
            
            glVertex3d(x - s, y - s, z - s);
            glVertex3d(x + s, y - s, z - s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y + s, z - s);
            glVertex3d(x + s, y - s, z - s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y + s, z - s);
            glVertex3d(x - s, y + s, z - s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x - s, y - s, z - s);
            glVertex3d(x - s, y + s, z - s);
            glEnd();
            glBegin(GL_LINES);

            glVertex3d(x - s, y - s, z - s);
            glVertex3d(x - s, y - s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y - s, z - s);
            glVertex3d(x + s, y - s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x + s, y + s, z - s);
            glVertex3d(x + s, y + s, z + s);
            glEnd();
            glBegin(GL_LINES);
            glVertex3d(x - s, y + s, z - s);
            glVertex3d(x - s, y + s, z + s);
            glEnd();
        }
    }

    void render_begin()
    {
        glClearColor(0.5f, 0.5f, 0.99f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(camera::x, camera::y, camera::z,
                  camera::ax, camera::ay, camera::az,
                  camera::vx, camera::vy, camera::vz);
    }
    void render_end()
    {
        glFlush();
        SDL_GL_SwapBuffers();
    }
    SDL_Surface* win;
    void init()
    {
        SDL_Init(SDL_INIT_VIDEO);
        win = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glMatrixMode(GL_PROJECTION);
        gluPerspective(45.0 * 640.0 / 480.0, 640.0 / 480.0, 0.1, 100);
        camera::x = 0;
        camera::y = 0;
        camera::z = 0;
        camera::ax = 0;
        camera::ay = 0;
        camera::az = 0;
        camera::vx = 0;
        camera::vy = 0;
        camera::vz = 0;
    }
    void quit()
    {
        SDL_Quit();
    }
}
