#include "miniRT.h"

t_ray	reverse_ray(t_ray ray, t_vec pos)
{
	t_ray new_ray;

	new_ray.pos = subs(ray.pos, pos);
	new_ray.dir = ray.dir; 

	return (new_ray);
}
