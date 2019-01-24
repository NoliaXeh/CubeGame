#pragma once

class Vector3
{
    public:
        Vector3() = default;
        Vector3(double x, double y, double z);
        ~Vector3() = default;
        
        double norm() const;
        Vector3& normalize();

        Vector3& rotate(const Vector3& angle);

        Vector3& operator=(const Vector3&) = default;
        Vector3 operator+(const Vector3& vect) const;
        Vector3 operator+(double n) const;
        Vector3 operator-(const Vector3& vect) const;
        Vector3 operator-(double n) const;
        Vector3 operator-() const;
        double operator*(const Vector3& vect) const;
        Vector3 operator*(double n) const;
        Vector3 operator^(const Vector3& vect) const;
        Vector3& operator^=(const Vector3& vect);
        Vector3& operator*=(double n);
        Vector3& operator+=(const Vector3& vect);
        Vector3& operator+=(double n);
        Vector3& operator-=(const Vector3& vect);
        Vector3& operator-=(double n);

        void get(double& x, double &y, double &z) const;
        void set(double x, double y, double z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(double x);
        void set_y(double y);
        void set_z(double z);
    private:
        double x_;
        double y_;
        double z_;
};
