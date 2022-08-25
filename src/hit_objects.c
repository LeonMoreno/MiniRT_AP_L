#include "miniRT.h"

double	plane_equation(t_ray ray, t_plane *plane)
{
	double t;
	double dDotN;
	t_vec	normalized;

	normalized = normalize(plane->vec_orien);
	dDotN = dot(ray.dir, plane->vec_orien);
	if (dDotN == 0)
		return (0);
	t = dot(vec_minus(plane->pos, ray.pos), normalized) / dDotN;
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
			inter.n = vec_minus(inter.point, plane->pos);
			//inter.n.len = length(length2(inter.n));
			inter.n = normalize(inter.n);
			inter.id = PL;
			if (inter.point.z > old_inter->point.z)
				*old_inter = inter;
		}
		plane = plane->next;
	}
	return ;
}
