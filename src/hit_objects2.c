/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:37:10 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/08 13:32:50 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cy_ty(t_ray r, t_cyli *cy, int one)
{
	double	b;
	double	a;
	double	c;
	double	num;

	a = (r.dir.x * r.dir.x) + (r.dir.y * r.dir.y);
	b = 2 * ((r.pos.x * r.dir.x) + (r.pos.y * r.dir.y));
	c = (r.pos.x * r.pos.x) + (r.pos.y * r.pos.y) - (cy->diam * cy->diam);
	num = sqrt((b * b) - (4 * a * c));
	if (one == 1)
		return ((-b - num) / (2 * a));
	return ((-b + num) / (2 * a));
}

double	cy_equat(t_ray r, t_cyli *cy, t_inter *inter, t_matrix m)
{
	double	t1;
	t_vec	vec;

	t1 = cy_ty(r, cy, 1);
	vec = vec_sum(r.pos, vec_scale(r.dir, t1));
	vec = vec_minus(vec, new_vec(0, 0, vec.z));
	inter->n = normalize(transform(vec, m));
	if (fabs(vec.z) <= cy->hei)
		return (t1);
	t1 = cy_ty(r, cy, -1);
	vec = vec_sum(r.pos, vec_scale(r.dir, t1));
	vec = vec_minus(vec, new_vec(0, 0, vec.z));
	inter->n = normalize(transform(vec, m));
	if (fabs(vec.z) <= cy->hei)
		return (t1);
	return (0);
}

double	caps_equation(t_cyli *cy, t_ray r, double i)
{
	t_plane	plane;
	double	t;

	plane.coor = new_vec(0, 0, cy->hei * i);
	plane.vec_orien = new_vec(0, 0, 1);
	t = plane_equation(r, &plane);
	if (t && cy->diam > vec_length(
			vec_minus(vec_sum(r.pos, vec_scale(r.dir, t)), plane.coor)))
		return (t);
	return (0);
}

double	cylinder_parts(t_ray r, t_cyli *cy, t_inter *inter, t_vec o)
{
	double		t[3];
	t_matrix	m;

	m = mamul(rotate_x(o.x), mamul(rotate_y(o.y),
				mamul(scale_ma(1), rotate_z(o.z))));
	r = reverse_ray(r, cy->coor, mainv(m));
	inter->id = SP;
	t[0] = cy_equat(r, cy, inter, m);
	t[1] = caps_equation(cy, r, 1);
	t[2] = caps_equation(cy, r, -1);
	if (!t[0] && !t[1] && !t[2])
		return (0);
	if (t[0] > 0 && (t[0] < t[1] || t[1] <= 0) && (t[0] < t[2] || t[2] <= 0))
		return (t[0]);
	inter->id = PL;
	inter->n = normalize(transform(new_vec(0, 0, cy->hei), m));
	if (t[1] > 0 && (t[1] < t[2] || t[2] <= 0))
		return (t[1]);
	return (t[2]);
}

void	hit_cy(t_ray ray, t_elem *scene, t_inter *old_inter)
{
	double	t;
	t_cyli	*cy;
	t_inter	inter;

	cy = scene->head_cy;
	while (cy)
	{
		t = cylinder_parts(ray, cy, &inter, cy->vec_orien);
		if (t > 0)
		{
			inter.hit = true;
			inter.point = vec_sum(ray.pos, vec_scale(ray.dir, t));
			inter.col = cy->rgb;
			inter.obj = (void *) cy;
			if (vec_length(vec_minus(inter.point, ray.pos))
				< vec_length(vec_minus(old_inter->point, ray.pos)))
				*old_inter = inter;
		}
		cy = cy->next;
	}
	return ;
}
