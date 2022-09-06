/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pri_ele_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:40 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/06 14:31:41 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_print_pl(t_mini *m)
{
	t_plane		*t;
	int			i;

	i = 1;
	t = m->ele.head_pl;
	while (t)
	{
		printf("\tPlane: No %d\n", i);
		printf ("%f,%f,%f %f,%f,%f %d,%d,%d\n", t->coor.x, t->coor.y, t->coor.z,
			t->vec_orien.x, t->vec_orien.y, t->vec_orien.z,
			t->rgb.r, t->rgb.g, t->rgb.b);
		t = t->next;
		i++;
	}
}

void	ft_print_cy(t_mini *m)
{
	t_cyli		*t;
	int			i;

	i = 1;
	t = m->ele.head_cy;
	while (t)
	{
		printf("\tCylinder: No %d\n", i);
		printf ("%f,%f,%f %f,%f,%f %f %f %d,%d,%d\n",
			t->coor.x, t->coor.y, t->coor.z,
			t->vec_orien.x, t->vec_orien.y, t->vec_orien.z,
			t->diam, t->hei,
			t->rgb.r, t->rgb.g, t->rgb.b);
		t = t->next;
		i++;
	}
}
