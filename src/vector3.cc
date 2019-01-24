#include <iostream>
#include <cmath>
#include "vector3.hh"

/* Constructors */
Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z)
{}

/* methods */
double Vector3::norm() const
{
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Vector3& Vector3::normalize()
{
    double n = 1 / this->norm();
    (*this) *= n;
    return *this;
}

/* Rotation */
Vector3& Vector3::rotate(const Vector3& angle)
{
    /*
    double n = this->norm();
    this->normalize();
    double xa, ya, za;
    angle.get(xa, ya ,za);
    
    //xa += std::acos(x_) * (std::asin(x_) > 0 ? 1 : -1);
    ya += std::acos(y_) * (std::asin(y_) > 0 ? 1 : -1);
    //za += std::acos(z_) * (std::asin(z_) > 0 ? 1 : -1);
    
    Vector3 tmp(xa, ya, za);
    tmp.normalize();
    tmp.get(xa, ya, za);
    std::cout << (ya / 3.1415 * 180) << '\n';
    x_ = std::cos(xa);
    //y_ = std::cos(ya);
    z_ = std::cos(za);
    this->normalize() *= n;
    return *this;*/
    double a = angle.z_;
    double x = std::cos(a) * x_ + std::sin(a) * y_;
    double y = -std::sin(a) * x_ + std::cos(a) * y_;
    double z = z_;
    x_ = x;
    y_ = y;
    z_ = z;
    return *this;
    a = angle.x_;
    z = std::cos(a) * z_ + std::sin(a) * y_;
    y = -std::sin(a) * z_ + std::cos(a) * y_;
    x = x_;
    x_ = x;
    y_ = y;
    z_ = z;
    a = angle.y_;
    x = std::cos(a) * x_ + std::sin(a) * z_;
    z = -std::sin(a) * x_ + std::cos(a) * y_;
    y = y_;
    x_ = x;
    y_ = y;
    z_ = z;
    return *this;
}

/* operators */

Vector3 Vector3::operator+(const Vector3& vect) const
{
    Vector3 v(vect);
    v += *this;
    return v;
}
Vector3 Vector3::operator+(double n) const
{
    Vector3 v(n, n, n);
    v += *this;
    return v;
}
Vector3 Vector3::operator-(const Vector3& vect) const
{
    return (*this + (-vect));
}
Vector3 Vector3::operator-(double n) const
{
    return (*this + (-Vector3(n, n, n)));
}
Vector3 Vector3::operator-() const
{
    return Vector3(-x_, -y_, -z_);
}
double Vector3::operator*(const Vector3& vect) const
{
    return vect.x_ * x_ + vect.y_ * y_ + vect.z_ * z_;
}
Vector3 Vector3::operator*(double n) const
{
    return Vector3(x_ * n, y_ * n, z_ * n);
}
Vector3 Vector3::operator^(const Vector3& /*vect*/) const
{
    std::cerr << "Vector3::operator^ : NO IMPLEMENTED YET\n";
    return Vector3(0, 0, 0);
}
Vector3& Vector3::operator^=(const Vector3& /*vect*/)
{
    std::cerr << "Vector3::operator^= : NO IMPLEMENTED YET\n";
    return *this;
}
Vector3& Vector3::operator*=(double n)
{
    x_ *= n;
    y_ *= n;
    z_ *= n;
    return *this;
}
Vector3& Vector3::operator+=(const Vector3& vect)
{
    x_ += vect.x_;
    y_ += vect.y_;
    z_ += vect.z_;
    return *this;
}
Vector3& Vector3::operator+=(double n)
{
    x_ += n;
    y_ += n;
    z_ += n;
    return *this;
}
Vector3& Vector3::operator-=(const Vector3& vect)
{
    x_ -= vect.x_;
    y_ -= vect.y_;
    z_ -= vect.z_;
    return *this;
}
Vector3& Vector3::operator-=(double n)
{
    x_ -= n;
    y_ -= n;
    z_ -= n;
    return *this;
}

/* getters */

void Vector3::get(double& x, double& y, double& z) const
{
    x = x_;
    y = y_;
    z = z_;
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

/* setters */

void Vector3::set(double x, double y, double z)
{
    x_ = x;
    y_ = y;
    z_ = z;
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

