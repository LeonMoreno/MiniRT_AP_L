#include "miniRT.h"

double	cy_equat(t_ray r, t_cyli *cy)
{
	double	t1;
	double	b;
	double	a;
	double	c;
	double	numSQRT;
	t_vec	vec;


	r = reverse_ray(r, cy->coor);
	a = (r.dir.x * r.dir.x) + (r.dir.y * r.dir.y);
	b = 2 * ((r.pos.x * r.dir.x) + (r.pos.y * r.dir.y));
	c = (r.pos.x * r.pos.x) + (r.pos.y * r.pos.y) - cy->diam;
	numSQRT = sqrt((b * b) - (4 * a * c));

	//printf("t: %f\n", t1);
//	if (numSQRT == 0)
//		return (0);
	t1 = (-b - numSQRT) / (2 * a); 
	vec = vec_sum(r.pos, vec_scale(r.dir, t1));
	if (fabs(vec.z) <= 10)
		return (t1);	
	t1 = (-b + numSQRT) / (2 * a);
	vec = vec_sum(r.pos, vec_scale(r.dir, t1));
	if (fabs(vec.z) <= 10)
		return (t1);
	return (0);
}

void	hit_cy(t_ray ray, t_elem *scene, t_inter *old_inter)
{
	double	t;
	t_cyli	*cy;
	t_inter	inter;

	cy = scene->head_cy;
	while (cy)
	{
		t = cy_equat(ray, cy);
		if (t)
			printf("t: %f\n", t);
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.n = normalize(vec_minus(inter.point, cy->coor));
			inter.id = SP;
			inter.col = cy->rgb;
			inter.obj = (void *) cy;
			if (vec_length(vec_minus(inter.point, ray.pos))
				< vec_length(vec_minus(old_inter->point, ray.pos)))
				*old_inter = inter;
			//if (inter.point.z > old_inter->point.z)
		}
		cy = cy->next;
	}
	return ;
}
