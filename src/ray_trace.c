/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:00:45 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 14:01:19 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	ray_hit(t_ray ray, t_elem *scene)
{
	t_inter	inter;

	inter.hit = false;
	inter.point.z = -RAY_T_MAX;
	hit_sp(ray, scene, &inter);
	hit_p(ray, scene, &inter);
	hit_cy(ray, scene, &inter);
	return (inter);
}
