/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/01 16:54:45 by agrenon          ###   ########.fr       */
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
	return (NULL);
}

t_job	init_job(t_mini *m, int	i)
{
	t_job	job;
	
	job.start = (i * (m->h_win / N_THREAD));
	if (!i)
		job.start = 0;
	job.end = ((i * (m->h_win / N_THREAD)) + (m->h_win / N_THREAD));
	if (i == N_THREAD - 1)
		job.end = m->h_win;
	job.mini = m;
	return (job);
}

void	thread_it(t_mini *m)
{
	int			i;
	pthread_t	thread[N_THREAD];
	t_job		job[N_THREAD];
	long long	ms1;
	long long	ms2;
	struct timeval	time;

	//GET TIME
	gettimeofday(&time, NULL);
	ms1 = time.tv_sec * 1000 + (long int) time.tv_usec / 1000;

	//THREAD RENDERING
	i = 0;
	while (i < N_THREAD)
	{
		job[i] = init_job(m, i);
		pthread_create(&thread[i], NULL, start_render, (void *) &job[i]);
		i++;
	}
	i = 0;
	while (i < N_THREAD)
		pthread_join(thread[i++], NULL);
	mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);

	//PRINT RENDER TIME
	gettimeofday(&time, NULL);
	ms2 = time.tv_sec * 1000 + (long int) time.tv_usec / 1000;
	printf("N_THREAD = %d Render time: %lld\n", N_THREAD, ms2 - ms1);
}
