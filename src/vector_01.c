#include "miniRT.h" 

t_vec	new_vec(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_scale(t_vec a, double t)
{
	return (new_vec(a.x * t, a.y * t, a.z * t));
}

t_vec	vec_divi(t_vec a, double t)
{
	return (new_vec(a.x / t, a.y / t, a.z / t));
}

t_vec	normalize(const t_vec v)
{
	return (vec_scale(v, 1.0 / vec_length(v)));
}

double	vec_length_sq(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec_length(t_vec v)
{
	return (sqrt(vec_length_sq(v)));
}
