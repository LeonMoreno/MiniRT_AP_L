#include "miniRT"

double	plane_equation(t_ray ray, t_scene *scene)
{
	double t;
	double dDotN;

	dDotN = dot(ray.dir, plane.n);
	if (dDotN == 0)
		return (0);
	t = dot(subs(plane.pos, ray.pos), plane.n) / dDotN;

	if (t <= RAY_T_MIN)
		return (0);
	return (t);
}

t_inter	plane_touch(t_ray ray, t_scene *scene)
{
	t_inter inter;
	double	t;

	t = plane_equation(ray, plane);
	if (t == 0)
	{
		inter.hit = false;
		return (inter);
	}
	inter.hit = true;
	inter.point = add(ray.pos, multn(ray.dir, t));
	inter.n = subs(inter.point, plane.pos);
	inter.n.len = length(length2(inter.n));
	inter.n = normalized(inter.n);
	inter.object = plane;
	return (inter);
}
