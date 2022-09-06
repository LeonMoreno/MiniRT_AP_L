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
