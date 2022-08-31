#include "miniRT.h"

t_cyli	*add_struc_cy(char *line)
{
	t_cyli *cy;

	cy = malloc(sizeof(t_cyli));
	cy->id = CY;
	line = line + 2;
	line = get_doub(line, &cy->coor.x);
	line = get_doub(line, &cy->coor.y);
	line = get_doub(line, &cy->coor.z);
	line = get_doub(line, &cy->vec_orien.x);
	line = get_doub(line, &cy->vec_orien.y);
	line = get_doub(line, &cy->vec_orien.z);
	cy->vec_orien = normalize(cy->vec_orien);
	line = get_doub(line, &cy->diam);
	line = get_doub(line, &cy->hei);
	line = get_int(line, &cy->rgb.r, true);
	line = get_int(line, &cy->rgb.g, true);
	line = get_int(line, &cy->rgb.b, true);
	check_line_len(line, 2, "Irrelevant data found at Line CY");
	check_cy(cy);
	cy->next = NULL;
	return (cy);
}

void	init_struc_cyli(char *line, t_mini *m)
{
	t_cyli	*tmp;

	if (m->ele.head_cy == NULL)
		m->ele.head_cy = add_struc_cy(line);
	else
	{
		tmp = m->ele.head_cy;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_struc_cy(line);
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
	//pl->vec_orien = normalize(pl->vec_orien);
	line = get_int(line, &pl->rgb.r, true);
	line = get_int(line, &pl->rgb.g, true);
	line = get_int(line, &pl->rgb.b, true);
	check_line_len(line, 2, "Irrelevant data found at Line PL");
	check_pl(pl);
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
	line = get_int(line, &sp->rgb.r, true);
	line = get_int(line, &sp->rgb.g, true);
	line = get_int(line, &sp->rgb.b, true);
	check_line_len(line, 2, "Irrelevant data found at Line SP");
	sp->next = NULL;
	return (sp);
}
