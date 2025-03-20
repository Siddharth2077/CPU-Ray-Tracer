#pragma once

#include "raytracer.h"

class hit_record;

/// @brief Abstract class for any object that's hittable by a ray to render on the scene.
class hittable {
public:

    virtual ~hittable() = default;

    virtual bool hit(const ray& r, float ray_tmin, float ray_tmax, hit_record& hit_rec) const = 0;
    
};

class hit_record {
public:
    point3 hit_point;
    vector3 hit_normal;
    float t;
    bool hit_front_face;

    // Sets the hit record normal vector and decides if it hit front face or not.
    /// @param r Ray
    /// @param outward_normal Takes in the unit normal vector of the hit (ensure that it's a normalized vector).
    void set_face_normal(const ray& r, const vector3& outward_normal) {
        // If dot product < 0 = hit the front face (ray and outward normal are in same direction)
        // If dot product > 0 = hit the back face (ray and outward normal are opposite direction)
        hit_front_face = dot_product(r.direction(), outward_normal) < 0 ? true : false;
        hit_normal = hit_front_face ? outward_normal : -outward_normal;
    }
};


