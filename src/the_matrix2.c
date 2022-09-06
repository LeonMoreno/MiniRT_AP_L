#include "miniRT.h"

t_matrix	mamul(t_matrix m, t_matrix n)
{
	t_matrix	o;

	o.x[0] = (m.x[0] * n.x[0]) + (m.x[1] * n.y[0]) + (m.x[2] * n.z[0]);
	o.x[1] = (m.x[0] * n.x[1]) + (m.x[1] * n.y[1]) + (m.x[2] * n.z[1]);
	o.x[2] = (m.x[0] * n.x[2]) + (m.x[1] * n.y[2]) + (m.x[2] * n.z[2]);
	o.y[0] = (m.y[0] * n.x[0]) + (m.y[1] * n.y[0]) + (m.y[2] * n.z[0]);
	o.y[1] = (m.y[0] * n.x[1]) + (m.y[1] * n.y[1]) + (m.y[2] * n.z[1]);
	o.y[2] = (m.y[0] * n.x[2]) + (m.y[1] * n.y[2]) + (m.y[2] * n.z[2]);
	o.z[0] = (m.z[0] * n.x[0]) + (m.z[1] * n.y[0]) + (m.z[2] * n.z[0]);
	o.z[1] = (m.z[0] * n.x[1]) + (m.z[1] * n.y[1]) + (m.z[2] * n.z[1]);
	o.z[2] = (m.z[0] * n.x[2]) + (m.z[1] * n.y[2]) + (m.z[2] * n.z[2]);
	//printf("o.x :%f o.y: %f o.z: %f\n", o.x[1], o.y[2], o.z[0]);
	return (o);
}

double	dt(t_matrix m)
{
	return (((m.x[0] * m.y[1] * m.z[2]) + (m.x[1] * m.y[2] * m.z[0])
		+ (m.x[2] * m.y[0] * m.z[2])) - ((m.z[0] * m.y[1] * m.x[2])
		+ (m.z[1] * m.y[2] * m.x[0]) + (m.z[2] * m.y[0] * m.z[1])));
}

t_matrix	mainv(t_matrix m)
{
	double	d;
	t_matrix	o;

	d = dt(m);
	o.x[0] = ((m.y[1] * m.z[2]) - (m.z[1] * m.y[2])) / d;
	o.y[0] = (((m.y[0] * m.z[2]) - (m.z[0] * m.y[2])) * -1) / d;
	o.z[0] = ((m.y[0] * m.z[1]) - (m.z[0] * m.y[1])) / d;
	o.x[1] = (((m.x[1] * m.z[2]) - (m.z[1] * m.x[2])) *-1) / d;
	o.y[1] = ((m.x[0] * m.z[2]) - (m.z[0] * m.x[2])) / d;
	o.z[1] = (((m.x[0] * m.z[1]) - (m.z[0] * m.x[1])) * -1) / d;
	o.x[2] = ((m.x[1] * m.y[2]) - (m.y[1] * m.x[2])) / d;
	o.y[2] = (((m.x[0] * m.y[2]) - (m.y[0] * m.x[2])) * -1) / d;
	o.z[2] = ((m.x[0] * m.y[1]) - (m.y[0] * m.x[1])) / d;
	return (o);
}
