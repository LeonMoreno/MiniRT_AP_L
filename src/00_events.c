/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:02 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/14 13:23:45 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	event_ca(t_mini *m, int k)
{
	if (k == 46)
		m->ele.ca.origi.x += 5;
	if (k == 45)
		m->ele.ca.origi.x -= 5;
	if (k == 3)
		m->ele.ca.fov += 5;
	if (k == 2)
		m->ele.ca.fov -= 5;
	if (k == 45 || k == 46 || k == 3 || k == 5)
		start_render(m);
}

void	event_sp(t_mini *m, int k)
{
	if (m->e_sp && m->e_sp->id == SP && k == 4)
		m->e_sp->r += 3;
	else if (m->e_sp && m->e_sp->id == SP && k == 5 && m->e_sp->r > 3)
		m->e_sp->r -= 3;
	if (m->e_sp && k == 125)
		m->e_sp->center.y += 2.5;
	else if (m->e_sp && k == 126)
		m->e_sp->center.y -= 2.5;
	else if (m->e_sp && k == 123)
		m->e_sp->center.x -= 2.5;
	else if (m->e_sp && k == 124)
		m->e_sp->center.x += 2.5;
	if (m->e_sp && (k == 4 || k == 5 || k == 126 || k == 125
			|| k == 123 || k == 124))
		start_render(m);
}

void	event_cy_rot(t_mini *m, int k)
{
	if (m->e_cy && m->e_cy->id == CY && k == 6)
		m->e_cy->vec_orien.x += 0.1;
	else if (m->e_cy && m->e_cy->id == CY && k == 7)
		m->e_cy->vec_orien.x -= 0.1;
	if (m->e_cy && m->e_cy->id == CY && k == 8)
		m->e_cy->vec_orien.y += 0.1;
	else if (m->e_cy && m->e_cy->id == CY && k == 9)
		m->e_cy->vec_orien.y -= 0.1;
}

void	event_cy(t_mini *m, int k)
{
	if (m->e_cy && m->e_cy->id == CY && k == 14)
		m->e_cy->diam += 2.5;
	if (m->e_cy && m->e_cy->id == CY && k == 12)
		m->e_cy->diam -= 2.5;
	if (m->e_cy && m->e_cy->id == CY && k == 13)
		m->e_cy->hei += 2.5;
	if (m->e_cy && m->e_cy->id == CY && k == 1)
		m->e_cy->hei -= 2.5;
	if (m->e_cy && k == 125)
		m->e_cy->coor.y += 2.5;
	else if (m->e_cy && k == 126)
		m->e_cy->coor.y -= 2.5;
	else if (m->e_cy && k == 123)
		m->e_cy->coor.x -= 2.5;
	else if (m->e_cy && k == 124)
		m->e_cy->coor.x += 2.5;
	event_cy_rot(m, k);
	if (m->e_cy && (k == 14 || k == 12 || k == 13 || k == 1 || k == 125
			|| k == 126 || k == 123 || k == 124 || k == 6 || k == 7
			|| k == 8 || k == 9))
		start_render(m);
}

void	event_pl(t_mini *m, int k)
{
	if (m->e_pl && k == 126)
		m->e_pl->coor.y += 7;
	else if (m->e_pl && k == 125)
		m->e_pl->coor.y -= 7;
	else if (m->e_pl && k == 123)
		m->e_pl->coor.x -= 7;
	else if (m->e_pl && k == 124)
		m->e_pl->coor.x += 7;
	if (m->e_pl && (k == 125 || k == 126 || k == 123 || k == 124))
		start_render(m);
}
