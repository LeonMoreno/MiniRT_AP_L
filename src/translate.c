/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:39:04 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/08 15:13:23 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	reverse_ray(t_ray ray, t_vec pos, t_matrix m)
{
	t_ray	new_ray;

	new_ray.pos = transform(vec_minus(ray.pos, pos), m);
	new_ray.dir = transform(ray.dir, m);
	return (new_ray);
}
