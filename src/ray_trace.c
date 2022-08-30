#include "miniRT.h"

t_inter	ray_hit(t_ray ray, t_elem *scene)
{
	t_inter inter;

	inter.hit = false;
	inter.point.z = -RAY_T_MAX;
	hit_sp(ray, scene, &inter);
	hit_p(ray, scene, &inter);
	hit_cy(ray, scene, &inter);
	
	return (inter);
}
