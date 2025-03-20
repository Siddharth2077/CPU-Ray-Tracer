#pragma once

#include "raytracer.h"
#include "hittable.h"

class sphere : public hittable {
private:
    point3 center;
    float radius;

public:
    sphere(const point3& sphere_center, float sphere_radius) : center(sphere_center), radius(std::fmaxf(0.0f, sphere_radius)) {};

    // Implements virtual base method of 'hittable'.
    bool hit(const ray& r, float ray_tmin, float ray_tmax, hit_record& hit_rec) const override {        
        vector3 sphere_center = center - r.origin();				// C - Q (Vector towards sphere center, from origin of the ray)

        float a = r.direction().length_squared();					                    // a
        float b = -2.0f * dot_product(r.direction(), sphere_center);	                // b
        float c = dot_product(sphere_center, sphere_center) - (radius * radius);		// c

        // Compute discriminant (b^2 - 4ac)
        float discriminant = (b * b) - (4 * (a * c));

        if (discriminant < 0.0f)
            return false;
        
        float discriminant_root = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range (tmin to tmax)
        float root = (-b - discriminant_root) / (2.0f * a);         // First root of the quad. eqn. (closest)
        if (root <= ray_tmin || root >= ray_tmax) {                 // If first root out of range
            root = (-b + discriminant_root) / (2.0f * a);           // Second root of the quad. eqn.
            if (root <= ray_tmin || root >= ray_tmax)
                return false;                                       // Both roots out of range (no hit with sphere)
        }

        // Found a root within range. Populate the hit record
        hit_rec.t = root;
        hit_rec.hit_point = r.at(hit_rec.t);
        vector3 outward_normal = (hit_rec.hit_point - center) / radius;
        hit_rec.set_face_normal(r, outward_normal);

        return true;
    }


};