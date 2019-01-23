#pragma once
#include "vector3.hh"

class Cube
{
    public:
        Cube();
        Cube(double size);
        Cube(const Cube& cube) = default;
        ~Cube();
        Cube& operator=(const Cube&);
        void render_at(double x, double y, double z);
        void render_at(const Vector3& pos);

    protected:
        double size_;

};
