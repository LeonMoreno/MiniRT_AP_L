#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include <math.h>
# include <mlx.h>
#include <stdbool.h>

// Libs
# include "essential.h"
# include "elements.h"

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f
# define AMBIENT 0.2

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
	double		intensity;
	t_al		al;
	t_camera	ca;
	t_light		li;
	t_sphere	*head_sp;
	t_plane		*head_pl;
	t_cyli		*head_cy;
}	t_elem;

typedef struct	s_inter
{
	bool	hit;
	t_vec	point;
	t_vec	n;
	int		id;
	void	*obj;
	t_color	col;
}				t_inter;

typedef struct s_mini
{
	void	*mlx;
	void	*win;
	t_img	i;
	double	aspe_ratio;
	int		h_win;
	int		w_win;
	double	fov;
	int		control;
	t_elem	ele;
	t_sphere 	*ob;
	t_sphere 	*e_sp;
	t_plane 	*e_pl;
	t_cyli		*e_cy;
	t_vec		ens;
}	t_mini;

//MLX
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	mlx_start(t_mini *m);
void		start_render(t_mini *m);

// Start scene && parsing
void		start_scene(int argc, char **argv, t_mini *m);
void		start_resolution(t_mini *m);
void		start_camera(t_mini *m);

//Tracer
void	start_render(t_mini *m);
t_inter	ray_hit(t_ray ray, t_elem *scene);
void	hit_p(t_ray ray, t_elem *scene, t_inter *old_inter);
void	hit_sp(t_ray ray, t_elem *scene, t_inter *old_inter);
t_inter	camera_ray(t_mini *m, int i, int j);
void	hit_cy(t_ray ray, t_elem *scene, t_inter *old_inter);

//Ray manipulation
t_ray	reverse_ray(t_ray ray, t_vec pos, t_matrix m);

//Light
int		ft_shading(t_inter, t_elem *scene);

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
void		check_li(t_light li);
void		check_pl(t_plane *pl);
void		check_cy(t_cyli *c);
void		check_rgb(int x);
void		check_line_len(char *l, int x, char *s);

//Utils
void	ft_free_arr2(char **s);
void	ft_free(t_mini *m);
void	ft_msg_err(char *s);
void	ft_print_sp(t_mini *m);
void	ft_print_ele(t_mini *m);
void	ft_print_al(t_mini *m);
void	ft_print_cy(t_mini *m);
void	ft_print_pl(t_mini *m);
void	ft_print_ca(t_mini *m);


//Hooks & Events
void	start_hooks(t_mini *m);
void	event_sp(t_mini *m, int k);
void	event_cy(t_mini *m, int k);

#endif
