#include "miniRT.h"

void	init_struc_sphere(char *line, t_mini *m)
{
	t_sphere	*tmp;

	if (m->ele.head_sp == NULL)
		m->ele.head_sp = add_struc_sphere(line);
	else
	{
		tmp = m->ele.head_sp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_struc_sphere(line);
	}
}

t_ligth	init_struc_light(char *line)
{
	t_ligth	li;

	li.id = LI;
	line++;
	line = get_doub(line, &li.point.x);
	line = get_doub(line, &li.point.y);
	line = get_doub(line, &li.point.z);
	line = get_doub(line, &li.bri);
	return (li);
}

t_camera	init_struc_camera(char *line)
{
	t_camera	ca;

	ca.id = CA;
	line++;
	line = get_doub(line, &ca.origi.x);
	line = get_doub(line, &ca.origi.y);
	line = get_doub(line, &ca.origi.z);
	line = get_doub(line, &ca.vec_orien.x);
	line = get_doub(line, &ca.vec_orien.y);
	line = get_doub(line, &ca.vec_orien.z);
	line = get_int(line, &ca.fov);
	return (ca);
}

t_al	init_struc_al(char *line)
{
	t_al	al;

	al.id = AL;
	line++;
	line = get_doub(line, &al.al_ratio);
	line = get_int(line, &al.rgb.r);
	line = get_int(line, &al.rgb.g);
	line = get_int(line, &al.rgb.b);
	return (al);
}

void	line_parser(char *line, t_mini *m)
{
	//printf("line = %s", line);
	if (!ft_strncmp(line, "A", 1))
		m->ele.al = init_struc_al(line);
	else if (!ft_strncmp(line, "C", 1))
		m->ele.ca = init_struc_camera(line);
	else if (!ft_strncmp(line, "L", 1))
		m->ele.li = init_struc_light(line);
	else if (!ft_strncmp(line, "sp", 2))
		init_struc_sphere(line, m);
	else if (!ft_strncmp(line, "pl", 2))
		init_struc_plane(line, m);
	else if (!ft_strncmp(line, "cy", 2))
		init_struc_cyli(line, m);
}
