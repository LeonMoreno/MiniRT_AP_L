/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/01 14:17:12 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	camera_ray(t_mini *m, int i, int j)
{
	t_inter	inter;
	t_ray	cam_ray;
	t_vec	dir;
	//double	fov;

	//fov = 60 * M_PI / 180;
	dir = new_vec(j - (m->w_win / 2), i - (m->h_win / 2), -1 * m->w_win / (2 * tanf(m->fov / 2)));
	cam_ray.dir = normalize(dir);
	cam_ray.pos = m->ele.ca.origi;
	inter = ray_hit(cam_ray, &m->ele);
	return (inter);
}

int	find_color(t_mini *m, int i, int j)
{
	t_inter	inter;

	inter = camera_ray(m, i, j);
	if (inter.hit)
//		return(0x00FFFF);
		return (ft_shading(inter, &m->ele));
	return (0x000000);
}

void	start_render(t_mini *m)
{
	int	i;
	int	j;
	int	color;


	m->fov = (double) m->ele.ca.fov * M_PI / 180;
	m->ele.li.bri = m->ele.li.bri * 10000;
	i = 0;
	while (i < m->h_win)
	{
		j = 0;
		while (j < m->w_win)
		{
			//COLOR HERE;
			color = find_color(m, i, j);
			my_mlx_pixel_put(&m->i, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);
}
