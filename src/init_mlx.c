#include "miniRT.h"

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
	m->i.addr = mlx_get_data_addr(m->i.img,
			&m->i.bits_pp, &m->i.ll, &m->i.endian);
}
