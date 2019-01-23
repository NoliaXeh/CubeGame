#include "cube.hh"
#include <iostream>

Cube::Cube() : size_(1)
{}

Cube::Cube(double size) : size_(size)
{}

Cube::~Cube()
{}

void Cube::render_at(double x, double y, double z)
{
    std::cout    << "Cube("
            << size_
            << ") rendered at ("
            << x
            << ' '
            << y
            << ' '
            << z <<
            ")\n";
}
void Cube::render_at(const Vector3& pos)
{
    double x, y, z;
    pos.get(x, y, z);
    render_at(x, y, z);
}
