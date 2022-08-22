#ifndef ELEMENTS_H
# define ELEMENTS_H

enum 
{
	AMB_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLI,
};

typedef	struct	s_al
{
	int		id;
	double	al_ratio;
	t_color	rgb;
}	t_al;

typedef struct s_camera
{
	int		id;
	t_vec	origi;
	t_vec	horizo;
	t_vec	verti;
	t_color	ll_corner;
}	t_camera;

typedef	struct	s_ligth
{
	int		id;
	t_vec	light_point;
	double	light_bri;
}	t_ligth;

typedef	struct	s_sphere
{
	int			id;
	t_vec		center;
	double		r;
	t_color		rgb;
	struct	s_sphere	*next;
}	t_sphere;

typedef	struct	s_plane
{
	int		id;
	t_vec	coor;
	t_vec	vec_orientation;
	t_color	rgb;
	struct s_plane	*next;
}	t_plane;

typedef	struct	s_cyli
{
	int		id;
	t_vec	coor;
	t_vec	vec_orientation;
	double	diameter;
	double	height;
	t_color	rgb;
	struct s_cyli	*next;
}	t_cyli;

#endif
