#include "miniRT.h"

void	event_mouse(t_mini *m, int k)
{
	if (m->e_sp && m->e_sp->id == SP && k == 4)
		m->e_sp->r += 5;
	else if (m->e_sp && m->e_sp->id == SP && k == 5)
		m->e_sp->r -= 5;
	else if (m->e_sp && k == 125)
		m->e_sp->center.y += 0.7;
	else if (m->e_sp && k == 126)
		m->e_sp->center.y -= 0.7;
	else if (m->e_sp && k == 123)
		m->e_sp->center.x -= 0.7;
	else if (m->e_sp && k == 124)
		m->e_sp->center.x += 0.7;
	if (k == 4 || k == 5 || k == 126 || k == 125 || k == 123 || k == 124)
		start_render(m);
}
