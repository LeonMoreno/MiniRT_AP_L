#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_mini	*m;

	m = malloc(sizeof(t_mini));
	start_scene(argc, argv, m);
	ft_print_ele(m);
	mlx_start(m);
	thread_it(m);
	mlx_loop(m->mlx);
	ft_free(m);
	return (0);
}
