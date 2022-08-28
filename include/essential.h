#ifndef ESSENTIAL_H
# define ESSENTIAL_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
<<<<<<< HEAD
	t_vec	pos;
	t_vec	dir;
} t_ray;
=======
	t_vec	origi;
	t_vec	dire;
}	t_ray;
>>>>>>> start_parsing

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

t_vec	new_vec(double x, double y, double z);
t_vec	vec_sum(t_vec a, t_vec b);
t_vec	vec_minus(t_vec a, t_vec b);
t_vec	vec_scale(t_vec a, double t);
t_vec	vec_divi(t_vec a, double t);
double	vec_length_sq(t_vec v);
<<<<<<< HEAD
double    vec_length(t_vec v);
double    dot(t_vec a, t_vec b);

t_vec    normalize(const t_vec v);
t_vec vec_cross(const t_vec a, const t_vec b);
=======
double	vec_length(t_vec v);
double	dot_product(t_vec a, t_vec b);
t_vec	normalize(const t_vec v);
t_vec	vec_cross(const t_vec a, const t_vec b);
>>>>>>> start_parsing

double	min(double num1, double num2);
double	max(double num1, double num2);

#endif
