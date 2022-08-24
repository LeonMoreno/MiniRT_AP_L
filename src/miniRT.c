#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_mini	*m;

	m = malloc(sizeof(t_mini));
	start_scene(argc, argv, m);
	ft_print_sp(m);
	//mlx_start(m);
	//start_render(m);
	//mlx_put_image_to_window(m->mlx, m->win, m->i.img, 0, 0);
	//mlx_loop(m->mlx);
	return (0);
}
