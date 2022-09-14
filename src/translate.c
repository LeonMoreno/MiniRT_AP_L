/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:39:04 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/14 12:42:12 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	transform_r(t_vec vec, t_matrix ma)
{
	t_vec		new_vec;
	t_matrix	matrix;

	matrix = mainv(ma);
	new_vec.x = vec.x * matrix.x[0] + vec.y * matrix.x[1] + vec.z * matrix.x[2];
	new_vec.y = vec.x * matrix.y[0] + vec.y * matrix.y[1] + vec.z * matrix.y[2];
	new_vec.z = vec.x * matrix.z[0] + vec.y * matrix.z[1] + vec.z * matrix.z[2];
	return (new_vec);
}

t_vec	apply_matrices(t_vec vec, t_vec o)
{
	return (transform(transform(transform(vec, rotate_z(o.z)), rotate_y(o.y)), rotate_x(o.x)));
}

t_vec	apply_matrices_r(t_vec vec, t_vec o)
{
	return (transform_r(transform_r(transform_r(vec, rotate_x(o.x)), rotate_y(o.y)), rotate_z(o.z)));
}

t_ray	reverse_ray(t_ray ray, t_vec pos, t_vec o)
{
	t_ray	new_ray;

	new_ray.pos = apply_matrices_r(vec_minus(ray.pos, pos), o);
	new_ray.dir = apply_matrices_r(ray.dir, o);
	return (new_ray);
}
