#include "vector3.hh"

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z)
{}

void Vector3::get(double& x, double& y, double& z) const
{
    x = x_;
    y = y_;
    z = z_;
}

void Vector3::set(double x, double y, double z)
{
    x_ = x;
    y_ = y;
    z_ = z;
}

double Vector3::get_x() const
{
    return x_;
}

double Vector3::get_y() const
{
    return y_;
}

double Vector3::get_z() const
{
    return z_;
}

void Vector3::set_x(double x)
{
    x_ = x;
}

void Vector3::set_y(double y)
{
    y_ = y;
}

void Vector3::set_z(double z)
{
    z_ = z;
}
