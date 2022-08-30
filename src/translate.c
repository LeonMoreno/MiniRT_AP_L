#include "miniRT.h"

//t_vec	reverse_

t_ray	reverse_ray(t_ray ray, t_vec pos)
{
	t_ray new_ray;

	new_ray.pos = transform(vec_minus(ray.pos, pos));
	new_ray.dir = transform(ray.dir); 

	return (new_ray);
}
