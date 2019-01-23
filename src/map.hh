#include <iostream>
#include "vector3.hh"
class Map
{
public:
    Map(const Vector3& dim);
    Map(const Vector3& dim, int seed);
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;
    ~Map();
    void generate();
    int getat(const Vector3& pos) const;
    void setat(const Vector3& pos, const int id);
    void fillat(const Vector3& pos, const Vector3& dim, int id);
    const Vector3& getsize() const;
private:
    const Vector3 dim_;
    const int seed_;
    int *map_;
};
