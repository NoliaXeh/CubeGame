#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "graphics.hh"


namespace graphics::camera
{
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
}
namespace graphics
{
    void render_cube(double x, double y, double z)
    {
        glBegin(GL_QUADS);
        double s = 1;
        s /= 2;
        int r = 120, g = 255, b = 50;
        double l = 0.7;
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
        glVertex3d(x + s, y + s, z + s); // + + +
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x - s, y + s, z - s); // - + -
        glVertex3d(x - s, y + s, z + s); // - + +
        l = 0.6;
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
        glVertex3d(x + s, y - s, z + s); // + - +
        glVertex3d(x + s, y - s, z - s); // + - -
        glVertex3d(x + s, y + s, z - s); // + + -
        glVertex3d(x + s, y + s, z + s); // + + +
        l = 0.7;
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
        glVertex3d(x - s, y - s, z + s); // - - +
        glVertex3d(x - s, y - s, z - s); // - - -
        glVertex3d(x + s, y - s, z - s); // + - -
        glVertex3d(x + s, y - s, z + s); // + - +
        l = 0.6;
        //back
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
        glVertex3d(x - s, y - s, z + s);
        glVertex3d(x - s, y - s, z - s);
        glVertex3d(x - s, y + s, z - s);
        glVertex3d(x - s, y + s, z + s);
        l = 1;
        //up
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
        glVertex3d(x - s, y - s, z + s);
        glVertex3d(x - s, y + s, z + s);
        glVertex3d(x + s, y + s, z + s);
        glVertex3d(x + s, y - s, z + s);
        l = 0.3;
        //down
        glColor3ub((int)(r * l), (int)(g * l), (int)(b * l));
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
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        gluPerspective(70.0 * 640.0 / 480.0, 640.0 / 480.0, 0.1, 100);
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
