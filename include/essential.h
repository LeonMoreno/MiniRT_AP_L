/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essential.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:47:07 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/13 16:08:25 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_vec	pos;
	t_vec	dir;
}	t_ray;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_matrix
{
	double	x[3];
	double	y[3];
	double	z[3];

}				t_matrix;

t_vec		new_vec(double x, double y, double z);
t_vec		vec_sum(t_vec a, t_vec b);
t_vec		vec_minus(t_vec a, t_vec b);
t_vec		vec_scale(t_vec a, double t);
t_vec		vec_divi(t_vec a, double t);
double		vec_length_sq(t_vec v);
double		vec_length(t_vec v);
double		dot(t_vec a, t_vec b);
t_vec		normalize(const t_vec v);
t_vec		inverse(t_vec vec);
t_vec		vec_cross(const t_vec a, const t_vec b);
//double	dot_product(t_vec a, t_vec b);

double		min(double num1, double num2);
double		max(double num1, double num2);

//Maxtrix
t_vec		transform(t_vec vec, t_matrix m);
t_vec		transform_r(t_vec vec, t_matrix ma);
t_matrix	mamul(t_matrix m, t_matrix n);
t_matrix	scale_ma(double scale);
t_matrix	rotate_x(double thet);
t_matrix	rotate_y(double thet);
t_matrix	rotate_z(double thet);
t_matrix	mainv(t_matrix m);
#endif
