#pragma once

#include "raytracer.h"
#include "hittable.h"
#include <vector>

class hittable_list : public hittable {
public:
    // Members:
    std::vector<shared_ptr<hittable>> objects;

    // Constructors:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) {
        add_object_to_list(object);
    }

    // Methods:
    inline void add_object_to_list(shared_ptr<hittable> object) {objects.push_back(object);}
    inline void clear_objects_list() {objects.clear();}

    // Overrides:
    bool hit(const ray& r, float ray_tmin, float ray_tmax, hit_record& hit_rec) const override {
        hit_record temp_hit_record;
        bool hit_anything {false};
        float closest_hit_so_far = ray_tmax;

        // Iterate through each object, find the closest hit for this ray (like depth test)
        for (const auto& object : objects) {
            if (object->hit(r, ray_tmin, closest_hit_so_far, temp_hit_record)) {
                hit_anything = true;
                closest_hit_so_far = temp_hit_record.t;
                hit_rec = temp_hit_record;                  // update the main hit record (passed into the function)
            }
        }

        return hit_anything;
    }

};