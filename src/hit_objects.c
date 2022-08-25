#include "miniRT.h"

double	sphere_equation(t_ray ray, t_sphere *s, t_vec to_light)
{
	double	t1;
	double	b;
	double	c;
	double	delta;

	//to_light = normalize(to_light);
	b = 2 * dot(ray.dir, to_light);
	c = vec_length_sq(vec_minus(ray.pos, s->center)) - (s->r * s->r);
	delta = (b * b) - (4 * c);
	if (delta <= 0)
		return (0);
	t1 = (-b - sqrt(delta)) / 2;
	if (t1 > 0)
		return (t1);
	t1 = (-b + sqrt(delta)) / 2;
	if (t1 > 0)
		return (t1);
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

double	plane_equation(t_ray ray, t_plane *plane)
{
	double t;
	double dDotN;
	t_vec	normalized;

	normalized = normalize(plane->vec_orien);
	dDotN = dot(ray.dir, plane->vec_orien);
	if (dDotN == 0)
		return (0);
	t = dot(vec_minus(plane->coor, ray.pos), normalized) / dDotN;
	if (t <= RAY_T_MIN)
		return (0);
	return (t);
}

void	hit_p(t_ray ray, t_elem *scene, t_inter *old_inter)
{
	double		t;
	t_plane	*plane;
	t_inter		inter;

	plane = scene->head_pl;
	while (plane)
	{
		t = plane_equation(ray, plane);
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.n = normalize(vec_minus(inter.point, plane->coor));
			inter.id = PL;
			inter.col = plane->rgb; 
			inter.obj = (void *) plane;
			if (inter.point.z > old_inter->point.z)
				*old_inter = inter;
		}
		plane = plane->next;
	}
	return ;
}
