/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/08 11:30:31 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	camera_ray(t_mini *m, int i, int j)
{
	t_inter		inter;
	t_ray		cam_ray;
	t_vec		dir;
	t_matrix	ma;

	ma = mamul(rotate_x(m->ele.ca.vec_orien.x), mamul(rotate_y(m->ele.ca.vec_orien.y), mamul(scale_ma(1), rotate_z(m->ele.ca.vec_orien.z))));
	dir = new_vec(j - (m->w_win / 2), i - (m->h_win / 2),
			-1 * m->w_win / (2 * tanf(m->fov / 2)));
	cam_ray.dir = normalize(dir);
	cam_ray.pos = m->ele.ca.origi;
	cam_ray = reverse_ray(cam_ray, new_vec(0, 0, 0), mainv(ma));
	inter = ray_hit(cam_ray, &m->ele);
	return (inter);
}

int	find_color(t_mini *m, int i, int j)
{
	t_inter	inter;

	inter = camera_ray(m, i, j);
	if (inter.hit)
		return (ft_shading(inter, &m->ele));
	return (0x000000);
}

void	start_render(t_mini *m)
{
	int	i;
	int	j;
	int	color;

	m->fov = (double) m->ele.ca.fov * M_PI / 180;
	m->ele.intensity = m->ele.li.bri * 10000;
	i = 0;
	while (i < m->h_win)
	{
		j = 0;
		while (j < m->w_win)
		{
			color = find_color(m, i, j);
			my_mlx_pixel_put(&m->i, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);
}
