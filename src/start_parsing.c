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
	printf("LIGHT = %d id__%d\n", LI, li.id);
	printf("LI_x = %f\n", li.point.x);
	printf("LI_y = %f\n", li.point.y);
	printf("LI_z = %f\n", li.point.z);
	printf("LI_BRi = %f\n", li.bri);
	printf("line = %s", line);
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
	printf("CAMERA = %d id__%d\n", CA, ca.id);
	printf("CA____x = %f\n", ca.origi.x);
	printf("CA____y = %f\n", ca.origi.y);
	printf("CA____z = %f\n", ca.origi.z);
	printf("FOV = %d\n", ca.fov);
	printf("line = %s", line);
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
	printf("LUz_AMBIENTE = %d\n", AL);
	printf("al_Ratio = %f\n", al.al_ratio);
	printf("__R = %d\n", al.rgb.r);
	printf("__g = %d\n", al.rgb.g);
	printf("__B = %d\n", al.rgb.b);
	printf("line = %s", line);
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
}
