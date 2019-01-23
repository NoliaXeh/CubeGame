#include <iostream>

#include "cube.hh"
#include "vector3.hh"
#include "map.hh"
#include "graphics.hh"

int main()
{
    graphics::init();
    Map map(Vector3(100, 100, 30), 1000);
    map.generate();
    std::cout << map.getat(Vector3(0, 0, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 1, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 2, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 3, 0)) << std::endl;
    std::cout << map.getat(Vector3(2, 0, 2)) << std::endl;
    int dx = 1;
    int dy = 0;
    for (;;)
    {
        
        graphics::render_begin();
        if (graphics::camera::x == 100 && graphics::camera::y == 0)
        {
            dx = 0;
            dy = 1;
        }
        else if (graphics::camera::y == 100 && graphics::camera::x == 0)
        {
            dy = -1;
            dx = 0;
        }
        else if (graphics::camera::x == 100 && graphics::camera::y == 100)
        {
            dx = -1;
            dy = 0;
        }
        else if (graphics::camera::y == 0 && graphics::camera::x == 0)
        {
            dx = 1;
            dy = 0;
        }
        graphics::camera::x += dx;
        graphics::camera::y += dy;
        graphics::camera::z = 25;
        graphics::camera::ax = 50;
        graphics::camera::ay = 50;
        graphics::camera::az = 0;
        graphics::camera::vx = 0;
        graphics::camera::vy = 0;
        graphics::camera::vz = 1;
        double dx, dy, dz;
        map.getsize().get(dx, dy, dz);
        int margin = 5;
        for (double x = margin; x < dx - margin; x++)
            for (double y = margin; y < dy - margin; y++)
                for (double z = 0; z < dz - 0; z++)
                {
                    graphics::render_cube(x, y, z, map.getat(Vector3(x, y, z)));
                }
        graphics::render_end();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                exit(0);
        }
    }
}
