#include <iostream>

#include "cube.hh"
#include "vector3.hh"
#include "map.hh"
#include "graphics.hh"
#include "player.hh"

int main()
{
    graphics::init();
    Map map(Vector3(100, 100, 30), 666);
    map.generate();
    Player p(Vector3(20, 20, 20), "Nolia");
    p.trace();
    p.bind_camera();
    for (;;)
    {
        
        graphics::render_begin();
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
                goto end_of_the_game;
        }
        p.update();
        p.render();
    }
end_of_the_game:
    p.untrace();
    SDL_Quit();
}
