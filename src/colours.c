#include "miniRT.h"

double	ft_intensity(t_inter inter, t_elem *scene, t_vec to_light, double llen)
{
	double	intensity;
	
	to_light = normalize(to_light);	
	intensity = 0;;
	if (inter.id == SP)
		intensity = (scene->intensity * (dot(to_light, inter.n)))/ (llen * llen);
	if (inter.id == CY)
		intensity = (scene->intensity * (dot(to_light, inter.n)))/ (llen * llen);
	if (inter.id == PL)
		intensity = scene->intensity /(llen * llen);
	
	//printf("intensity: %f\n", intensity);
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
	len  = vec_length(to_light);
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
		//if (intensity > 2)
		//	printf("intensity %f\n", intensity);
	//	if (inter.id == SP)
	//	reste = (intensity - 1) * (intensity - 1) * 255;
//		intensity = 1;
	}
	//printf("intensityL %f color rouge : %d\n", scene->al.al_ratio,(int) scene->al.rgb.r);
	trgb[0] = 0;
	trgb[1] = (char) min(255, ((reste + inter.col.r)
		* ((((scene->al.al_ratio * ((double) scene->al.rgb.r / 255))) + intensity))));
	trgb[2] = (char) min(255, ((reste + inter.col.g)
		* ((((scene->al.al_ratio * ((double) scene->al.rgb.g / 255))) + intensity))));
	trgb[3] = (char) min(255, ((reste + inter.col.b)
		* ((((scene->al.al_ratio * ((double) scene->al.rgb.b / 255))) + intensity))));
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}
