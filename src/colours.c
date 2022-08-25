#include "miniRT.h"

double	ft_intensity(t_inter inter, t_elem *scene, t_vec to_light, double llen)
{
	double	intensity;
	
	to_light = normalize(to_light);	
	intensity = 0;;
	if (inter.id == SP)
		intensity = (scene->li.bri * (dot(to_light, inter.n)))/ (llen * llen);
	if (inter.id == PL)
	{
		intensity = scene->li.bri /(llen * llen);
	}
	//printf("intensity: %f\n", intensity);
	return (intensity);
}

bool	l_crossed(t_inter inter, t_vec to_light, t_elem *scene)
{
	t_ray	ray;
	t_inter	new_inter;
	double	len;
	double	llen;
	
	ray.pos = inter.point;
	ray.dir = to_light;
	len  = vec_length(ray.dir);
	ray.dir = normalize(ray.dir);
	new_inter = ray_hit(ray, scene);
	llen = vec_length(vec_minus(new_inter.point, ray.pos));
	if (new_inter.hit && new_inter.id == SP) //&& llen < len)
	{
		if (new_inter.id == SP)
			printf("len %f llen %f: diff %f\n", len, llen, llen - len);
		return (true);
	}
	return (false);
}

int	ft_shading(t_inter inter, t_elem *scene)
{
	unsigned char trgb[4];
	double	intensity;
	double	reste;
	t_vec	to_light;

	intensity = 0;
	to_light = vec_minus(scene->li.point, inter.point);
	if (!l_crossed(inter, to_light, scene))
		intensity = ft_intensity(inter, scene, to_light, vec_length(to_light));
	reste = 0;
	if (intensity < 0)
		intensity = 0;
	else if (intensity > 1)
	{
//		reste = (intensity - 1) * (intensity - 1) * 255;
		intensity = 1;
	}
	trgb[0] = 0;
	trgb[1] = (char) min(255, ((reste + inter.col.r) * (AMBIENT + intensity)));
	trgb[2] = (char) min(255, ((reste + inter.col.g) * (AMBIENT + intensity)));
	trgb[3] = (char) min(255, ((reste + inter.col.b) * (AMBIENT + intensity)));
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}
