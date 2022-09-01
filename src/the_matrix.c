
#include "miniRT.h"

t_matrix	rotate_x(double thet)
{
	t_matrix	matrix;

//	thet = thet * 90;
	matrix.x[0] = 1;
	matrix.x[1] = 0;
	matrix.x[2] = 0;
	matrix.y[0] = 0;
	matrix.y[1] = cosf(thet);
	matrix.y[2] = (-1) * sinf(thet);
	matrix.z[0] = 0;
	matrix.z[1] = sinf(thet);
	matrix.z[2] = cosf(thet);
	//matrix.z[2] = (-1) * cosf(thet);
	return (matrix);
}

t_matrix	rotate_y(double thet)
{
	t_matrix	matrix;

	//thet = thet * 90;
	matrix.x[0] = cosf(thet);
	matrix.x[1] = 0;
	matrix.x[2] = sinf(thet);
	matrix.y[0] = 0;
	matrix.y[1] = 1;
	matrix.y[2] = 0;
	matrix.z[0] = (-1) * sinf(thet);
	matrix.z[1] = 0;
	matrix.z[2] = cosf(thet);
	return (matrix);
}

t_matrix	rotate_z(double thet)
{
	t_matrix	matrix;

//	thet = thet * 90;
	matrix.x[0] = cosf(thet);
	matrix.x[1] = (-1) * sinf(thet);
	matrix.x[2] = 0;
	matrix.y[0] = sinf(thet);
	matrix.y[1] = cosf(thet);
	matrix.y[2] = 0;
	matrix.z[0] = 0;
	matrix.z[1] = 0;
	matrix.z[2] = 1;
	return (matrix);
}

t_matrix	scale_ma(double scale)
{
	t_matrix	matrix;

	
	matrix.x[0] = scale;
	matrix.x[1] = 0;
	matrix.x[2] = 0;
	matrix.y[0] = 0;
	matrix.y[1] = scale;
	matrix.y[2] = 0;
	matrix.z[0] = 0;
	matrix.z[1] = 0;
	matrix.z[2] = scale;
	return (matrix);
}

t_vec	transform(t_vec vec, t_matrix matrix)
{
	t_vec		new_vec;

	new_vec.x = vec.x * matrix.x[0] + vec.y * matrix.x[1] + vec.z * matrix.x[2];
	new_vec.y = vec.x * matrix.y[0] + vec.y * matrix.y[1] + vec.z * matrix.y[2];
	new_vec.z = vec.x * matrix.z[0] + vec.y * matrix.z[1] + vec.z * matrix.z[2];
	return (new_vec);
}
