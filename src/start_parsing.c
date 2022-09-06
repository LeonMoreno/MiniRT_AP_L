#include "miniRT.h"

void	init_struc_sphere(char *line, t_mini *m)
{
	static int	i = 1;
	t_sphere	*tmp;

	if (m->ele.head_sp == NULL)
	{
		m->ele.head_sp = add_struc_sphere(line);
		m->ele.head_sp->num = i;
	}
	else
	{
		i++;
		tmp = m->ele.head_sp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_struc_sphere(line);
		tmp->next->num = i;
	}
}

t_light	init_struc_light(char *line, t_mini *m)
{
	t_light	li;

	if (m->l == true)
		ft_msg_err("Only one LiNE L is Allowed\n");
	li.id = LI;
	line++;
	line = get_doub(line, &li.point.x);
	line = get_doub(line, &li.point.y);
	line = get_doub(line, &li.point.z);
	line = get_doub(line, &li.bri);
	check_line_len(line, 0, "Irrelevant data found at Line L\n");
	check_li(li);
	m->l = true;
	return (li);
}

t_camera	init_struc_camera(char *line, t_mini *m)
{
	t_camera	ca;

	if (m->c == true)
		ft_msg_err("Only one LiNE C is Allowed\n");
	ca.id = CA;
	line++;
	line = get_doub(line, &ca.origi.x);
	line = get_doub(line, &ca.origi.y);
	line = get_doub(line, &ca.origi.z);
	line = get_doub(line, &ca.vec_orien.x);
	line = get_doub(line, &ca.vec_orien.y);
	line = get_doub(line, &ca.vec_orien.z);
	line = get_int(line, &ca.fov, false);
	check_line_len(line, 0, "Irrelevant data found at Line C\n");
	check_ca(ca);
	m->c = true;
	return (ca);
}

t_al	init_struc_al(char *line, t_mini *m)
{
	t_al	al;

	if (m->a == true)
		ft_msg_err("Only one LiNE A is Allowed\n");
	al.id = AL;
	line++;
	line = get_doub(line, &al.al_ratio);
	line = get_int(line, &al.rgb.r, true);
	line = get_int(line, &al.rgb.g, true);
	line = get_int(line, &al.rgb.b, true);
	check_line_len(line, 0, "Irrelevant date found at Line A\n");
	check_al(al);
	m->a = true;
	return (al);
}

void	line_parser(char *line, t_mini *m)
{
	if ((!ft_strncmp(line, "A", 1)))
		m->ele.al = init_struc_al(line, m);
	else if (!ft_strncmp(line, "C", 1))
		m->ele.ca = init_struc_camera(line, m);
	else if (!ft_strncmp(line, "L", 1))
		m->ele.li = init_struc_light(line, m);
	else if (!ft_strncmp(line, "sp", 2))
		init_struc_sphere(line, m);
	else if (!ft_strncmp(line, "pl", 2))
		init_struc_plane(line, m);
	else if (!ft_strncmp(line, "cy", 2))
		init_struc_cyli(line, m);
}
