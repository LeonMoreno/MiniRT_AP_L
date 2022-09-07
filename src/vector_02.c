/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:03:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 14:04:04 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_sum(t_vec a, t_vec b)
{
	return (new_vec(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec	vec_minus(t_vec a, t_vec b)
{
	return (new_vec(a.x - b.x, a.y - b.y, a.z - b.z));
}

double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vec_cross(const t_vec a, const t_vec b)
{
	return (new_vec(a.y * b.z - a.z * b.y, a.z
			* b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

t_vec	inverse(t_vec vec)
{
	return (new_vec(-vec.x, -vec.y, -vec.z));
}
