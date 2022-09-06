/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:22 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/06 14:31:23 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	event_li(t_mini *m, int k)
{
	if (k == 18)
		m->ele.li.point.x -= 5;
	if (k == 19)
		m->ele.li.point.x += 5;
	if (k == 20)
		m->ele.li.point.y -= 5;
	if (k == 21)
		m->ele.li.point.y += 5;
	if (k == 18 || k == 19 || k == 20 || k == 21)
		start_render(m);
}
