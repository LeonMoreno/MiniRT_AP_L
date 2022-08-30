#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include <math.h>
# include <mlx.h>
#include <stdbool.h>

// Libs
# include "essential.h"
# include "elements.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		ll;
	int		endian;
}	t_img;

typedef struct s_elem
{
	t_al		al;
	t_camera	ca;
	t_ligth		li;
	t_sphere	*head_sp;
	t_plane		*head_pl;
	t_cyli		*head_cy;
}	t_elem;

typedef struct s_mini
{
	void	*mlx;
	void	*win;
	t_img	i;
	double	aspe_ratio;
	int		h_win;
	int		w_win;
	int		control;
	t_elem	ele;
	t_vec	ens;
}	t_mini;

void		mlx_start(t_mini *m);
void		start_render(t_mini *m);

// Start scene && parsing
void		start_scene(int argc, char **argv, t_mini *m);
void		start_resolution(t_mini *m);
void		start_camera(t_mini *m);

// Parser
void		line_parser(char *line, t_mini *m);
int			ft_whitespace(char c);
char		*get_doub(char *line, double *al_ratio);
char		*get_int(char *line, unsigned char *r, bool b);
void		init_struc_plane(char *line, t_mini *m);
void		init_struc_cyli(char *line, t_mini *m);
t_sphere	*add_struc_sphere(char *line);
void		check_al(t_al al);
void		check_ca(t_camera ca);
void		check_li(t_ligth li);
void		check_pl(t_plane *pl);
void		check_cy(t_cyli *c);
void		check_rgb(int x);

//Utils
void		ft_free_arr2(char **s);
void		ft_free(t_mini *m);
void		ft_msg_err(char *s);
void		ft_print_ele(t_mini *m);
void		ft_print_pl(t_mini *m);
void		ft_print_cy(t_mini *m);

#endif
