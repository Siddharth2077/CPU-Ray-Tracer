
#include "raytracer.h"
#include "sphere.h"
#include "hittable.h"
#include "hittable_list.h"


color ray_color(const ray& r, const hittable& world_object) {
	hit_record hit_rec;
	if (world_object.hit(r, 0.0f, f_infinity, hit_rec)) {
		// OBJECT SHADING:
		return (hit_rec.hit_normal + color(1, 1, 1)) * 0.5f;		// Shading with normals (shift from [-1, 1] to [0, 1])		
	}

	// GRADIENT BACKDROP (Sky):
	vector3 unit_direction = unit_vector(r.direction());
	// Converts the y-scale from [-1, +1] to [0, 2]. Then multiplies by 0.5 to get final scale [0, +1]
	float a = 0.5f * (unit_direction.y() + 1.0f);
	// Linear Interpolation: blendedValue = (1−a)⋅startValue + a⋅endValue
    return (1.0f - a) * color(1.0f, 1.0f, 1.0f) + a * color(0.5f, 0.7f, 1.0f);
}


int main() {

	// Image

	int max_color_value {255};
	float aspect_ratio = 16.0f / 9.0f;
	int image_width = 1000;

	// Calculate the image height based on aspect ratio (ensure its atleast 1)
	int image_height = int (image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;


	// World
	hittable_list world;
	world.add_object_to_list(make_shared<sphere>(point3(0.0f, 0.0f, -1.0f), 0.5f));
	world.add_object_to_list(make_shared<sphere>(point3(0.0f, -100.5f, -1.0f), 100.0f));

	// Camera

	float focal_length = 1.0f;							// Distance between camera and viewport origin
	float viewport_height = 2.0f;
	float viewport_width = viewport_height * (float(image_width)/image_height);
	auto camera_center = point3(0, 0, 0);

	// Calculate the vectors across the horizontal and down the vertical viewport edges
	auto viewport_u = vector3(viewport_width, 0, 0);	// Vu = horizontal
	auto viewport_v = vector3(0, -viewport_height, 0);	// Vv = vertical

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel (pixel 0,0)
	auto viewport_upper_left = (
		camera_center
		- vector3(0, 0, focal_length)
		- (viewport_u / 2)
		- (viewport_v / 2)
	);
	auto pixel_00_location = viewport_upper_left + (0.5f * (pixel_delta_u + pixel_delta_v));



	// Render as .ppm image:

	std::cout << "P3\n" << image_width << " " << image_height << "\n" << max_color_value << std::endl;

	for (int j{0}; j < image_height; j++) {
		for (int i{0}; i < image_width; i++) {

			auto current_pixel_center = pixel_00_location + (i * pixel_delta_u) + (j * pixel_delta_v);
			
			auto ray_direction = current_pixel_center - camera_center;		// Gives a vector pointing to current pixel from the camera as the origin
			ray ray_to_current_pixel = ray(camera_center, ray_direction);

			color pixel_color = ray_color(ray_to_current_pixel, world);

			write_color(std::cout, pixel_color);

		}
	}

}