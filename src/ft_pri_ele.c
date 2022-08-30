#include "miniRT.h"

void	ft_print_sp(t_mini *m)
{
	t_sphere	*t;
	int			i;

	i = 1;
	t = m->ele.head_sp;
	while (t)
	{
		printf("\tSphere: No %d\n", i);
		printf ("%f,%f,%f %f %d,%d,%d\n", t->center.x, t->center.y, t->center.z,
			t->r, t->rgb.r, t->rgb.g, t->rgb.b);
		t = t->next;
		i++;
	}
}

void	ft_print_li(t_mini *m)
{
	double	x;
	double	y;
	double	z;
	double	bri;

	x = m->ele.li.point.x;
	y = m->ele.li.point.y;
	z = m->ele.li.point.z;
	bri = m->ele.li.bri;
	printf("\tLight:\n");
	printf ("%f %f %f %f\n", x, y, z, bri);
}

void	ft_print_ca(t_mini *m)
{
	printf("\tCamera:\n");
	printf ("%f,%f,%f %f,%f,%f %d\n", m->ele.ca.origi.x,
		m->ele.ca.origi.y, m->ele.ca.origi.z,
		m->ele.ca.vec_orien.x, m->ele.ca.vec_orien.y,
		m->ele.ca.vec_orien.z, m->ele.ca.fov);
}

void	ft_print_al(t_mini *m)
{
	printf("\n\tAmbient lightning:\n");
	printf ("%f %d,%d,%d\n", m->ele.al.al_ratio, m->ele.al.rgb.r,
		m->ele.al.rgb.g, m->ele.al.rgb.b);
}

void	ft_print_ele(t_mini *m)
{
	if (m->ele.al.id == AL)
		ft_print_al(m);
	if (m->ele.ca.id == CA)
		ft_print_ca(m);
	if (m->ele.li.id == LI)
		ft_print_li(m);
	ft_print_sp(m);
	ft_print_pl(m);
	ft_print_cy(m);
}
