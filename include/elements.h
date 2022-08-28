#ifndef ELEMENTS_H
# define ELEMENTS_H

enum
{
	AL,
	CA,
	LI,
	SP,
	PL,
	CY,
};

typedef struct s_al
{
	int		id;
	double	al_ratio;
	t_color	rgb;
}	t_al;

typedef struct s_camera
{
	int				id;
	t_vec			origi;
	t_vec			h;
	t_vec			v;
	t_vec			ll_corner;	
	t_vec			vec_orien;
	unsigned char	fov;
}	t_camera;

typedef struct s_ligth
{
	int		id;
	t_vec	point;
	double	bri;
}	t_light;

typedef struct s_sphere
{
	int				id;
	t_vec			center;
	double			r;
	t_color			rgb;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	int		id;
	t_vec	coor;
	t_vec	vec_orien;
	t_vec	n;
	t_color	rgb;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cyli
{
	int				id;
	t_vec			coor;
	t_vec			vec_orien;
	double			diam;
	double			hei;
	t_color			rgb;
	struct s_cyli	*next;
}	t_cyli;

#endif
