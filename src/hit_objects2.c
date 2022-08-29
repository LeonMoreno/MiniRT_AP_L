#include "miniRT.h"

double	sphere_equation(t_ray ray, t_cylindre *c)
{
	double	t1;
	double	b;
	double	c;
	double	numSQRT;

	a = (r.dir.x * r.dir.x) + (r.dir.y * r.dir.y);
	b = 2 * ((r.pos.x * r.dir.x) + (r.pos.y * r.dir.y));
	c = (r.pos.x * r.pos.x) + (r.pos.y * r.pos.y) - cylindre.r;
	numSQRT = sqrt((b * b) - 4 * a * c);
	t2 = (((-1) * b) + numSQRT) / (2 * a);
	
	if (delta <= 0)
		return (0);
	t1 = (((-1) * b) - numSQRT) / (2 * a); 
	if (fabs(ray.dir.z * t1) <= 1
		return (t1);	
	t1 = (-b + sqrt(delta)) / (2 * a);
	if (fabs(ray.dir.z * t1) <= 1
		return (t1);i
	return (0);
}

void	hit_sp(t_ray ray, t_elem *scene, t_inter *old_inter)
{
	double		t;
	t_sphere	*sphere;
	t_inter		inter;

	sphere = scene->head_sp;
	while (sphere)
	{
		t = sphere_equation(ray, sphere, vec_minus(ray.pos, sphere->center));
		//printf("t: %f\n", t);
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.n = normalize(vec_minus(inter.point, sphere->center));
			inter.id = SP;
			inter.col = sphere->rgb;
			inter.obj = (void *) sphere;
			if (inter.point.z > old_inter->point.z)
				*old_inter = inter;
		}
		sphere = sphere->next;
	}
	return ;
}
