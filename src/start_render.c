#include "miniRT.h"

t_ray	new_ray(t_vec a, t_vec b)
{
	t_ray r;

	r.origi.x = a.x;
	r.origi.y = a.y;
	r.origi.z = a.z;
	r.dire.x = b.x;
	r.dire.y = b.y;
	r.dire.z = b.z;
	return (r);
}

t_ray	start_ray(int i, int j, t_mrt *m)
{
	t_ray 	r;
	t_vec	res1;
	t_vec	res2;
	double u;
	double v;

	u = (double) i / m->w_win - 1;
	v = (double) j / m->h_win - 1;
	res1 = vec_sum(m->camera.ll_corner, vec_scale(m->camera.horizo, u));
	res2 = vec_minus(vec_scale(m->camera.verti, v), m->camera.origi);
	r = new_ray(m->camera.origi, vec_sum(res1, res2));
	return (r);
}

t_vec	make_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_vec c;

	c.x = r;
	c.y = g;
	c.z = b;
	return (c);
}

t_vec	ray_color(t_ray *r)
{
	double	t;
	t_vec	uni_dir;
	t_vec	res1;
	t_vec	res2;

	uni_dir = normalize(r->dire);
	t = 0.5 * (uni_dir.y + 1.0);
	printf("uni_dir.y %f t = %f\n", uni_dir.y, t);
	res1 = vec_scale(new_vec(1.0, 1.0, 1.0), (1.0 - t));
	res2 = vec_scale(new_vec(0.5, 0.7, 1.0), t);
	return (vec_sum(res1, res2));
}

int	mk_rgb(t_vec c)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){c.z * 255, c.y * 255, c.x * 255, t});
}

void	start_render(t_mrt *m)
{
	char	*dst;
	int		i;
	int		j;
	int		rgb;
	t_ray	r;
	t_vec	colo;

	j = 0;
	while (j < m->h_win)
	{
		i = 0;
		while (i < m->w_win)
		{
			r = start_ray(i, j, m);
			colo = ray_color(&r);
			//printf("%f, %f, %f\n", r.dire.x, r.dire.y, r.dire.z);
			rgb = mk_rgb(colo);
			dst = m->i.addr + j * m->i.ll + i * m->i.bits_pp / 8;
			*(unsigned int *)dst = rgb;
			i++;
		}
		j++;
	}
}
