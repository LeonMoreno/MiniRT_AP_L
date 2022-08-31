/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/08/31 17:01:03 by agrenon          ###   ########.fr       */
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
//		return(0x00FFFF);
		return (ft_shading(inter, &m->ele));
	return (0x000000);
}

void	*start_render(void *data)
{
	int		i;
	int		j;
	int		color;
	t_job	*jb;

	jb = (t_job *) data;
	i = jb->start;
	//printf("Threadi onhoing %d start: %d end: %d\n", i, jb->start, jb->end);
	while (i < jb->end)
	{
		j = 0;
		while (j < jb->mini->w_win)
		{
			//COLOR HERE;
			color = find_color(jb->mini, i, j);
			my_mlx_pixel_put(&jb->mini->i, j, i, color);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);
	return (NULL);
}

void	thread_it(t_mini *m)
{
	int			i;
	pthread_t	thread[16];
	t_job		job[16];

	i = 0;
	while (i < 16)
	{
		job[i].start = (i * (m->h_win / 16));
		if (!i)
			job[i].start = 0;
		job[i].end = ((i * (m->h_win / 16)) + (m->h_win / 16));

		if (i == 15)
			job[i].end = m->h_win;
	//	printf("Threadi onhoing %d start: %d end: %d\n", i, job[i].start, job[i]. end);
		job[i].mini = m;
		pthread_create(&thread[i], NULL, start_render, (void *) &job[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);
}


