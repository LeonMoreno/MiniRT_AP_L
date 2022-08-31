/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/08/31 14:43:30 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	camera_ray(t_mini *m, int i, int j)
{
	t_inter	inter;
	t_ray	cam_ray;
	t_vec	dir;
//	double	fov;

//	fov = 60 * M_PI / 180;
	dir = new_vec(j - (m->w_win / 2), i - (m->h_win / 2), -1 * m->w_win / (2 * tanf(FOV / 2)));
	cam_ray.dir = normalize(dir);
	cam_ray.pos = new_vec(0, 0, 0);
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
