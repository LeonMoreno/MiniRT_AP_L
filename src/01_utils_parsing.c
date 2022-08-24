#include "miniRT.h"

void	ft_print_sp(t_mini *m)
{
	t_sphere *tmp;

	tmp = m->ele.head_sp;
	while (tmp)
	{
		printf("Sphere ID = %d\n", tmp->id);
		printf("Sphere X = %f\n", tmp->center.x);
		printf("Sphere X = %f\n", tmp->center.y);
		printf("Sphere X = %f\n", tmp->center.z);
		tmp = tmp->next;
	}
}

t_sphere	*add_struc_sphere(char *line)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	sp->id = SP;
	line = line + 2;
	line = get_doub(line, &sp->center.x);
	line = get_doub(line, &sp->center.y);
	line = get_doub(line, &sp->center.z);
	line = get_doub(line, &sp->r);
	line = get_int(line, &sp->rgb.r);
	line = get_int(line, &sp->rgb.g);
	line = get_int(line, &sp->rgb.b);
	sp->next = NULL;
	return (sp);
}
