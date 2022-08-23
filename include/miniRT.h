#ifndef MINIRT_H
# define MINIRT_H

#include "../libft/include/libft.h"
#include <math.h>
#include <mlx.h>

// Libs
#include "essential.h"
#include "elements.h"

typedef	struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		ll;
	int		endian;
}	t_img;

typedef	struct	s_elem
{
	t_al		al;
	t_camera	ca;
	t_ligth		li;
	t_sphere	sp;
	t_plane		pl;
	t_cyli		cy;
}	t_elem;

typedef struct s_mini
{
	void	*mlx;
	void	*win;
	t_img	i;
	double	aspe_ratio;
	int		h_win;
	int		w_win;
	t_elem	ele;
}	t_mini;

void	mlx_start(t_mini *m);
void	start_render(t_mini *m);

// Start scene && parsing
void	start_scene(int argc, char **argv, t_mini *m);
void	ft_msg_err(char *s);
void	start_resolution(t_mini *m);
void	start_camera(t_mini *m);
void	line_parser(char *line, t_mini *m);

//Utils
void	ft_free_arr2(char **s);

#endif
