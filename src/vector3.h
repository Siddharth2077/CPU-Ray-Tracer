#pragma once

#include "raytracer.h"

class vector3 {
private:
    float x_component {};
    float y_component {};
    float z_component {};

public:

    // Conmstructors:
    vector3() : x_component(0.0f), y_component(0.0f), z_component(0.0f) {}
    vector3(float x, float y, float z) : x_component(x), y_component(y), z_component(z) {}

    // Getters:
    inline float x() const {return x_component;}
    inline float y() const {return y_component;}
    inline float z() const {return z_component;}
    inline float length_squared() const {return ((x_component * x_component) + (y_component * y_component) + (z_component * z_component));}
    inline float length() const {return std::sqrt(length_squared());}

    // Operator overloads:
    inline vector3 operator-() const {
        return vector3(-x_component, -y_component, -z_component);
    }    
    inline vector3& operator+=(const vector3& other) {
        x_component += other.x();
        y_component += other.y();
        z_component += other.z();
        return *this;
    }
    inline vector3& operator*=(float t) {
        x_component *= t;
        y_component *= t;
        z_component *= t;
        return *this;
    }
    inline vector3& operator/=(float t) {
        x_component /= t;
        y_component /= t;
        z_component /= t;
        return *this;
    }
};

// point3 is just an Alias for vector3, but useful for geometric clarity in the code.
using point3 = vector3;

// Non member operator overloads:
inline std::ostream& operator<<(std::ostream& out_stream, const vector3& vec3) {                // OUTPUT STREAM << 
    return out_stream << "(" << vec3.x() << ", " << vec3.y() << ", " << vec3.z() << ")"; 
}
inline vector3 operator+(const vector3& v, const vector3& other) {                              // ADDITION OF 2 VECTORS
    return vector3(v.x() + other.x(), v.y() + other.y(), v.z() + other.z());
} 
inline vector3 operator-(const vector3& v1, const vector3& v2) {                                // SUBTRACTION OF 2 VECTORS
    return vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
} 
inline vector3 operator*(const vector3& v, float t) {                                           // MULTIPLICATION WITH FLOAT
    return vector3(v.x() * t, v.y() * t, v.z() * t);
}
inline vector3 operator*(float t, const vector3& v) {                                           // MULTIPLICATION WITH FLOAT
    return v * t;
}
inline vector3 operator*(const vector3& v, const vector3& other) {                              // MULTIPLICATION OF 2 VECTORS  
    return vector3(v.x() * other.x(), v.y() * other.y(), v.z() * other.z());
}  
inline vector3 operator/(const vector3& v, float t) {                                           // DIVISION WITH FLOAT
    return v * (1/t);
}

// Vector utility functions:
inline vector3 unit_vector(const vector3& v) {
    return v / v.length();
}
inline float dot_product(const vector3&v1, const vector3& v2) {
    return (
        (v1.x() * v2.x()) +
        (v1.y() * v2.y()) + 
        (v1.z() * v2.z())
    );
}
inline vector3 cross_product(const vector3&v1, const vector3& v2) {
    return vector3(
        (v1.y() * v2.z() - v1.z() * v2.z()),
        (v1.z() * v2.x() - v1.x() * v2.z()),
        (v1.x() * v2.y() - v1.y() * v2.x())
    );
}
