#include "miniRT.h"

t_ray	reverse_ray(t_ray ray, t_vec pos, t_matrix m)
{
	t_ray new_ray;

	new_ray.pos = transform(vec_minus(ray.pos, pos), m);
	new_ray.dir = transform(ray.dir, m); 

	return (new_ray);
}
