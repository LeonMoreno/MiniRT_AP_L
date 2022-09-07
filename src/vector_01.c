/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:40:22 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 13:58:59 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h" 

t_vec	new_vec(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

inline t_vec	vec_scale(t_vec a, double t)
{
	return (new_vec(a.x * t, a.y * t, a.z * t));
}

inline t_vec	vec_divi(t_vec a, double t)
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
