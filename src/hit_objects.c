/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:06:02 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 14:36:29 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphere_equation(t_ray ray, t_sphere *s, t_vec to_light)
{
	double	t1;
	double	b;
	double	c;
	double	delta;

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
	t_sphere	*s;
	t_inter		inter;

	s = scene->head_sp;
	while (s)
	{
		t = sphere_equation(ray, s, vec_minus(ray.pos, s->center));
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.n = normalize(vec_minus(inter.point, s->center));
			inter.id = SP;
			inter.col = s->rgb;
			inter.obj = (void *) s;
			if (inter.point.z > old_inter->point.z)
				*old_inter = inter;
		}
		s = s->next;
	}
	return ;
}

double	plane_equation(t_ray ray, t_plane *plane)
{
	double	t;
	double	ddotn;
	t_vec	norm;

	norm = normalize(plane->vec_orien);
	ddotn = dot(ray.dir, plane->vec_orien);
	if (ddotn == 0)
		return (0);
	t = dot(vec_minus(plane->coor, ray.pos), norm) / ddotn;
	if (t <= RAY_T_MIN)
		return (0);
	return (t);
}

void	hit_p(t_ray ray, t_elem *scene, t_inter *old_inter)
{
	double		t;
	t_plane		*p;
	t_inter		inter;

	p = scene->head_pl;
	while (p)
	{
		t = plane_equation(ray, p);
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.n = normalize(vec_minus(inter.point, p->coor));
			inter.id = PL;
			inter.col = p->rgb;
			inter.obj = (void *) p;
			if (vec_length(vec_minus(inter.point, ray.pos))
				< vec_length(vec_minus(old_inter->point, ray.pos)))
			*old_inter = inter;
		}
		p = p->next;
	}
	return ;
}
