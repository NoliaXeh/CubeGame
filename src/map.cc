#include <iostream>
#include "map.hh"

Map::Map(const Vector3& dim)
    : Map(dim, 0)
{}

Map::Map(const Vector3& dim, int seed)
    : dim_(dim), seed_(seed)
    , map_(new int[int(dim.get_x()) * int(dim.get_y()) * int(dim.get_z())])
{}
Map::~Map()
{
    delete[] map_;
}
void Map::generate()
{
    double x, y, z;
    dim_.get(x, y, z);
    this->fillat(Vector3(0, 0, 0), Vector3(int(x), int(y), 1), 1);
    this->fillat(Vector3(0, 0, 1),
                Vector3(int(x), int(y), int(z - 1)),
                0);
}

static ssize_t geti(const Map& m, const Vector3& pos)
{
    ssize_t i = 0;
    auto size = m.getsize();
    double x, y, z;
    double sx, sy, sz;
    size.get(sx, sy, sz);
    pos.get(x, y, z);
    if (x < 0 or y < 0 or z < 0 or x >= sx or y >= sy or z >= sz)
        return -1;
    i += x;
    i += y * sx;
    i += z * sx * sy;
    return i;
}

int Map::getat(const Vector3& pos) const
{
    ssize_t i = geti(*this, pos);
    if (i < 0)
        return -1;
    return map_[i];
}

const Vector3& Map::getsize() const
{
    return dim_;
}

void Map::setat(const Vector3& pos, const int id)
{
    ssize_t i = geti(*this, pos);
    if (i < 0)
        return;
    map_[i] = id; 
}
void Map::fillat(const Vector3& pos, const Vector3& dim, int id)
{
    double px, py, pz;
    pos.get(px, py, pz);
    double dx, dy, dz;
    dim.get(dx, dy, dz);
    for (size_t x = px; x < dx; ++x)
        for (size_t y = py; y < dy; ++y)
            for (size_t z = pz; z < dz; ++z)
                this->setat(Vector3(x, y, z), id);
}
