#include "miniRT.h"

__attribute((always_inline)) inline t_vec	vec_sum(t_vec a, t_vec b)
{
	return (new_vec(a.x + b.x, a.y + b.y, a.z + b.z));
}

__attribute((always_inline)) inline t_vec	vec_minus(t_vec a, t_vec b)
{
	return (new_vec(a.x - b.x, a.y - b.y, a.z - b.z));
}

__attribute((always_inline)) inline double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

__attribute((always_inline)) inline t_vec	vec_cross(const t_vec a, const t_vec b)
{
	return (new_vec(a.y * b.z - a.z * b.y, a.z
			* b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

__attribute((always_inline)) inline t_vec	inverse(t_vec vec)
{
	return(new_vec(-vec.x, -vec.y, -vec.z));
}
