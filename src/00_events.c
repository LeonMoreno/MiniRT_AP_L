#include "miniRT.h"

void	event_sp(t_mini *m, int k)
{
	if (m->e_sp && m->e_sp->id == SP && k == 4)
		m->e_sp->r += 5;
	else if (m->e_sp && m->e_sp->id == SP && k == 5)
		m->e_sp->r -= 5;
	else if (m->e_sp && k == 125)
		m->e_sp->center.y += 2.5;
	else if (m->e_sp && k == 126)
		m->e_sp->center.y -= 2.5;
	else if (m->e_sp && k == 123)
		m->e_sp->center.x -= 2.5;
	else if (m->e_sp && k == 124)
		m->e_sp->center.x += 2.5;
	if (k == 4 || k == 5 || k == 126 || k == 125 || k == 123 || k == 124)
		start_render(m);
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
	if (k == 14 || k == 12 || k == 13 || k == 1)
		start_render(m);
}

