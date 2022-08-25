#include "miniRT.h"

int	ft_close(void)
{
	exit(0);
}

int	ft_key_hook(int keyhook, t_mini *m)
{
	m->ens = new_vec(0, 0, 0);
	if (keyhook == 53)
		ft_close();
	return (0);
}

int	mouse_mov(int b, int x, int y, t_mini *m)
{
	b = 0;
	//printf("Aqui TOY, %d %d %d\n", b, x, y);
	m->ens = new_vec(x, y, 0);
	printf("m->ens.x = %f\n", m->ens.x);
	return (0);
}

void	start_hooks(t_mini *m)
{
	mlx_hook(m->win, 17, 0, ft_close, 0);
	mlx_key_hook(m->win, ft_key_hook, m);
	mlx_hook(m->win, 5, 0, mouse_mov, m);
}

void	new_window(t_mini *m, char *msg)
{
	int	h;
	int	w;

	h = m->h_win;
	w = m->w_win;
	m->win = mlx_new_window(m->mlx, w, h, msg);
	start_hooks(m);
}

void	mlx_start(t_mini *m)
{
	m->mlx = mlx_init();
	new_window(m, "Hola miniRT");
	m->i.img = mlx_new_image(m->mlx, m->w_win, m->h_win);
	m->i.addr = mlx_get_data_addr(m->i.img, &m->i.bits_pp, &m->i.ll, &m->i.endian);
}
