/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:08:41 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/14 17:12:00 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	ft_intensity(t_inter inter, t_elem *scene, t_vec to_light, double l)
{
	double	intensity;

	to_light = normalize(to_light);
	intensity = 0;
	if (inter.id == SP)
		intensity = (scene->intensity * (dot(to_light, inter.n))) / (l * l);
	if (inter.id == CY)
		intensity = (scene->intensity * (dot(to_light, inter.n))) / (l * l);
	if (inter.id == PL)
		intensity = scene->intensity / (l * l);
	return (intensity);
}

bool	l_crossed(t_inter inter, t_vec to_light, t_elem *scene)
{
	t_ray	ray;
	t_inter	new_inter;
	double	len;
	double	llen;

	ray.pos = vec_sum(inter.point, vec_scale(normalize(to_light), 0.1));
	ray.dir = to_light;
	len = vec_length(to_light);
	ray.dir = normalize(ray.dir);
	new_inter = ray_hit(ray, scene);
	if (new_inter.hit)
	{
		llen = vec_length(vec_minus(new_inter.point, inter.point));
		if (llen <= len)
			return (true);
	}
	return (false);
}

char	mixe(double b, double li, t_elem *s, double i)
{
	return ((char) min(255, (b
				* (((s->al.al_ratio * ((double) li / 255))) + i))));
}

int	ft_shading(t_inter inter, t_elem *scene)
{
	unsigned char	trgb[4];
	double			intensity;
	double			reste;
	t_vec			to_light;

	intensity = 0;
	to_light = vec_minus(scene->li.point, inter.point);
	if (!l_crossed(inter, to_light, scene))
		intensity = ft_intensity(inter, scene, to_light, vec_length(to_light));
	reste = 0;
	if (intensity < 0)
		intensity = 0;
	else if (intensity > 1)
		intensity = 1;
	trgb[0] = 0;
	trgb[1] = mixe(reste + inter.col.r, scene->al.rgb.r, scene, intensity);
	trgb[2] = mixe(reste + inter.col.g, scene->al.rgb.g, scene, intensity);
	trgb[3] = mixe(reste + inter.col.b, scene->al.rgb.b, scene, intensity);
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}
