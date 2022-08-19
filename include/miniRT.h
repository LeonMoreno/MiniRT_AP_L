#ifndef MINIRT_H
# define MINIRT_H

#include "../libft/include/libft.h"
#include <math.h>
#include <mlx.h>

// Libs
#include "essential.h"

typedef	struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_mrt
{
	void	*mlx;
	void	*win;
	t_img	i;
	double	aspe_ratio;
	int		h_win;
	int		w_win;
	t_camera	camera;
}	t_mrt;


void	mlx_start(t_mrt *m);
void	start_render(t_mrt *m);

#endif
