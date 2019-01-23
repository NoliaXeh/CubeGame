#include "block.hh"

Block::Block()
    : color_{0, 0, 0}
    , opacity_(1)
    , id_(-1)
{}

Block::Block(char r, char g, char b, float opacity, int id)
    : color_ {r, g, b}
    , opacity_(opacity)
    , id_(id)
{}

void Block::render_at(double x, double y, double z)
{
    std::cout << "Block[" << id_ << "] rendered at (" << x << y << z << ")\n";
}

void Block::print()
{
    std::cout   << "Block {\n    id : " << id_
                << "\n    color : " << color_.r << ", " << color_.g << ", "
                << color_.b << "\n}\n";
}
