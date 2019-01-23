#include <iostream>
#include <cstdlib>
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

static size_t* noise(const Map& map, int seed, size_t max)
{
    size_t x = map.getsize().get_x();
    size_t y = map.getsize().get_y();
    std::srand(seed);
    size_t* res = new size_t[x * y];
    for (size_t i = 0; i < (x * y); ++i)
    {
        res[i] = std::rand() % max;
    }
    for (size_t k = 0; k < 8; ++k)
    {
        for (size_t i = 1; i < x - 1; ++i)
            for (size_t j = 1; j < y - 1; ++j)
            {
                size_t r = 0;
                r += res[i + j * x];
                r += res[i + 1 + j * x];
                r += res[i - 1 + j * x];
                r += res[i + (j + 1) * x];
                r += res[i + (j - 1) * x];
                res[i + j * x] = r / 5;
            }
    }
    return res;
}

void Map::generate()
{
    double x, y, z;
    dim_.get(x, y, z);
    /*
    this->fillat(Vector3(0, 0, 0), Vector3(int(x), int(y), 1), 1);
    this->fillat(Vector3(0, 0, 1),
                Vector3(int(x), int(y), int(z - 1)),
                0);
    */
    size_t* gen = noise(*this, seed_, 20);
    for (size_t i = 0; i < x * y; ++i)
    {
        size_t ix = i % (int)x;
        size_t iy = i / (int)y;
        this->setat(Vector3(ix, iy, gen[i]), 1);
    }
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
    for (size_t x = px; x < px + dx; ++x)
        for (size_t y = py; y < py + dy; ++y)
            for (size_t z = pz; z < pz + dz; ++z)
                this->setat(Vector3(x, y, z), id);
}
