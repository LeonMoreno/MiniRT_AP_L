#include "miniRT.h" 

t_vec	new_vec(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_multi(t_vec a, double t)
{
	return (new_vec(a.x * t, a.y * t, a.z * t));
}

t_vec	vec_divi(t_vec a, double t)
{
	return (new_vec(a.x / t, a.y / t, a.z / t));
}

t_vec	normalize(const t_vec v)
{
	return (vec_divi(v, vec_len(v)));
}

double	vec_len_sq(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec_len(t_vec v)
{
	return (sqrt(vec_len_sq(v)));
}
