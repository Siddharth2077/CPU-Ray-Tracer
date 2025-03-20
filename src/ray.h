#pragma once

#include "vector3.h"

class ray {
private:
    point3 orig;
    vector3 dir;

public:
    // Constructors:
    ray() {}
    ray(const point3& origin, const vector3& direction) : orig(origin), dir(direction) {}

    // Getters:
    inline const point3& origin() const {return orig;}
    inline const vector3& direction() const {return dir;}

    // Member methods:
    point3 at(float t) const {
        return orig + (t * dir);
    }

};