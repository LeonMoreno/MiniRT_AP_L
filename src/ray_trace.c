#include "miniRT.h"

t_inter	ray_hit(t_ray ray, t_elem *scene)
{
	t_inter inter;

	inter.hit = false;
	//hit_s();
	hit_p(ray, scene, &inter);
	//hit_cy();
	
	return (inter);
}
