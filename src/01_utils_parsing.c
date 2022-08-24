#include "miniRT.h"

void	ft_print_sp(t_mini *m)
{
	t_plane *tmp;

	tmp = m->ele.head_pl;
	while (tmp)
	{
		printf("Sphere ID = %d\n", tmp->id);
		printf("Sphere X = %f\n", tmp->coor.x);
		printf("Sphere X = %f\n", tmp->coor.y);
		printf("Sphere X = %f\n", tmp->coor.z);
		printf("Sphere X = %f\n", tmp->vec_orien.x);
		printf("Sphere X = %f\n", tmp->vec_orien.y);
		printf("Sphere X = %f\n", tmp->vec_orien.z);
		printf("Sphere X = %d\n", tmp->rgb.r);
		printf("Sphere X = %d\n", tmp->rgb.g);
		printf("Sphere X = %d\n", tmp->rgb.b);
		tmp = tmp->next;
	}
}

t_plane	*add_struc_plane(char *line)
{
	t_plane *pl;

	pl = malloc(sizeof(t_plane));
	pl->id = PL;
	line = line + 2;
	line = get_doub(line, &pl->coor.x);
	line = get_doub(line, &pl->coor.y);
	line = get_doub(line, &pl->coor.z);
	line = get_doub(line, &pl->vec_orien.x);
	line = get_doub(line, &pl->vec_orien.y);
	line = get_doub(line, &pl->vec_orien.z);
	line = get_int(line, &pl->rgb.r);
	line = get_int(line, &pl->rgb.g);
	line = get_int(line, &pl->rgb.b);
	pl->next = NULL;
	return (pl);
}

void	init_struc_plane(char *line, t_mini *m)
{
	t_plane	*tmp;

	if (m->ele.head_pl == NULL)
		m->ele.head_pl = add_struc_plane(line);
	else
	{
		tmp = m->ele.head_pl;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_struc_plane(line);
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
