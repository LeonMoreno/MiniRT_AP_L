#include "miniRT.h"

t_camera	init_struc_camera(char *line)
{
	t_camera ca;

	ca.id = CA;
	line++;
	line = get_bool(line, &ca.origi.x);
	line = get_bool(line, &ca.origi.y);
	line = get_bool(line, &ca.origi.z);
	line = get_bool(line, &ca.vec_orien.x);
	line = get_bool(line, &ca.vec_orien.y);
	line = get_bool(line, &ca.vec_orien.z);
	line = get_int(line, &ca.fov);
	printf("CA____x = %f\n", ca.origi.x);
	printf("CA____y = %f\n", ca.origi.y);
	return (ca);
}

t_al	init_struc_al(char *line)
{
	t_al 	al;

	al.id = AL;
	line++;
	line = get_bool(line, &al.al_ratio);
	line = get_int(line, &al.rgb.r);
	line = get_int(line, &al.rgb.g);
	line = get_int(line, &al.rgb.b);
	printf("al_Ratio = %f\n", al.al_ratio);
	printf("__R = %d\n", al.rgb.r);
	printf("__g = %d\n", al.rgb.g);
	printf("__B = %d\n", al.rgb.b);
	printf("line = %s\n", line);
	return (al);
}

void	line_parser(char *line, t_mini *m)
{
	//printf("line = %s", line);
	if (!ft_strncmp(line, "A", 1))
			m->ele.al = init_struc_al(line);
	else if (!ft_strncmp(line, "C", 1))
			m->ele.ca = init_struc_camera(line);
}
