#include <iostream>

#include "cube.hh"
#include "vector3.hh"
#include "map.hh"
#include "graphics.hh"

int main()
{
    graphics::init();
    Map map(Vector3(4, 3, 4), 42);
    map.generate();
    std::cout << map.getat(Vector3(0, 0, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 1, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 2, 0)) << std::endl;
    std::cout << map.getat(Vector3(0, 3, 0)) << std::endl;
    std::cout << map.getat(Vector3(2, 0, 2)) << std::endl;
    for (;;)
    {
        graphics::render_begin();
        std::cout << "**************\n";
        double dx, dy, dz;
        map.getsize().get(dx, dy, dz);
        for (double x = 0; x < dx; x++)
            for (double y = 0; y < dy; y++)
                for (double z = 0; z < dz; z++)
                {
                    if(map.getat(Vector3(x, y, z)))
                    {
                        graphics::render_cube(x, y, z);
                        std::cout << x << ' ' << y << ' ' << z << '\n';
                    }
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
