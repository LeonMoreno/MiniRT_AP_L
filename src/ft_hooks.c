#include "miniRT.h"

int	ft_close(void)
{
	exit(0);
}

int	ft_key_hook(int keyhook, t_mini *m)
{
	if (keyhook == 53)
		ft_close();
	/*if (keyhook == 12)
		m->ele.li.bri += -1000;
	if (keyhook == 13)
		m->ele.li.bri += 1000;*/
    event_sp(m, keyhook);
    event_cy(m, keyhook);
	if (keyhook == 35)
		ft_print_ele(m);
	printf("key = %d\n", keyhook);
	return (0);
}

int	mouse_cli(int b, int x, int y, t_mini *m)
{
	t_inter cli;

	if (b == 1)
	{
		cli = camera_ray(m, y, x);
		m->ob = (t_sphere *) cli.obj;
		if (m->ob->id == SP)
			m->e_sp = (t_sphere *) cli.obj;
		else if (m->ob->id == PL)
			m->e_pl = (t_plane *) cli.obj;
		else if (m->ob->id == CY)
		{
			printf("Voy A SELECC\n");
			m->e_cy = (t_cyli *) cli.obj;
		}
	}
	//printf("Aqui LLEGO %d x = %d y = %d %d\n", b, x, y, m->w_win);
	if (m->ob && (b == 1 && m->ob->id == SP))
		printf("Click sphere %d \n", m->e_sp->num);
	if (m->ob && (b == 1 && m->ob->id == PL))
		printf("Click Plane\n");
	if (m->ob && (b == 1 && m->ob->id == CY))
		printf("Click Cylinder\n");
    event_sp(m, b);
	return (0);
}

void	start_hooks(t_mini *m)
{
	m->e_sp = NULL;
	m->e_pl = NULL;
	mlx_hook(m->win, 17, 0, ft_close, 0);
	mlx_key_hook(m->win, ft_key_hook, m);
	mlx_mouse_hook(m->win, mouse_cli, m);
}
