#include "miniRT.h"

int	ft_close(void)
{
	exit(0);
}

int	ft_key_hook(int keyhook, t_mini *m)
{
	if (keyhook == 53)
		ft_close();
	if (keyhook == 12)
		m->ele.li.bri += -1000;
	if (keyhook == 13)
		m->ele.li.bri += 1000;
	if (m->e_pl && keyhook == 126)
	{
		m->e_pl->coor.x += 10;
		m->e_pl->coor.y += 10;
	}
	if (m->e_pl && keyhook == 125)
	{
		m->e_pl->coor.x -= 10;
		m->e_pl->coor.y -= 10;
	}
	if (m->e_sp && keyhook == 123)
	{
		m->e_sp->center.x -= 10;
		m->e_sp->center.y -= 10;
	}
	printf("key = %d\n", keyhook);
	start_render(m);
	return (0);
}

int	mouse_mov(int b, int x, int y, t_mini *m)
{
	t_inter cli;

	if (b == 1)
	{
		cli = camera_ray(m, y, x);
		m->ob = (t_sphere *) cli.obj;
		if (m->ob->id == 3)
			m->e_sp = (t_sphere *) cli.obj;
		else if (m->ob->id == 4)
			m->e_pl = (t_plane *) cli.obj;
	}
	//printf("%d x = %d y = %d %d\n", b, x, y, m->w_win);
	if (m->ob && (b == 1 && m->ob->id == SP))
		printf("Click sphere %d\n", m->e_sp->num);
	if (m->ob && (b == 1 && m->ob->id == PL))
		printf("Click Plane\n");
	if (m->e_sp && m->e_sp->id == SP && b == 4)
	{
		m->e_sp->r += 5;
		start_render(m);
	}
	if (m->e_sp && m->e_sp->id == SP && b == 5)
	{
		m->e_sp->r -= 5;
		start_render(m);
	}
	return (0);
}

void	start_hooks(t_mini *m)
{
	m->e_sp = NULL;
	m->e_pl = NULL;
	mlx_hook(m->win, 17, 0, ft_close, 0);
	mlx_key_hook(m->win, ft_key_hook, m);
	mlx_mouse_hook(m->win, mouse_mov, m);
}
