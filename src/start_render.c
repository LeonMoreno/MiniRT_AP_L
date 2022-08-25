#include "miniRT.h"


t_inter	camera_ray(t_scene *scene)
{
	t_inter	inter;
	t_ray	cam_ray;
	t_dir	dir;

	fov = 60 * M_PI / 180;
	dir = new_vec(j - (1080 / 2), i - (1080 / 2), -1 * img->w / (2 * tanf(fov / 2)));
	cam_ray.dir = dir;
	cam_ray
	cam_ray.pos = new_vec(0, 0, 0);
	inter = ray_shoot(cam_ray);
	return (inter);

}

int	color(t_scene *scene, int i, int j)
{
	t_inter	inter;

	inter = camera_ray(scene, i, j);

	return ();
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
			color = color(m->scene, i, j);
			j++;
		}
		i++;
	}
}
