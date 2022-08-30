#include "miniRT.h"

void	check_rgb(int x)
{
	if (x < 0 || x > 255)
		ft_msg_err("Not Valid Color\n");
}

void	check_al(t_al al)
{
	if (al.al_ratio < 0.0 || al.al_ratio > 1.0)
		ft_msg_err("Error Line A\n");
}

void	check_ca(t_camera ca)
{
	if (ca.vec_orien.x < -1.0 || ca.vec_orien.x > 1.0)
		ft_msg_err("Error Line C\n");
	if (ca.vec_orien.y < -1.0 || ca.vec_orien.y > 1.0)
		ft_msg_err("Error Line C\n");
	if (ca.vec_orien.z < -1.0 || ca.vec_orien.z > 1.0)
		ft_msg_err("Error Line C\n");
	if (ca.fov < 0 || ca.fov > 180)
		ft_msg_err("Error Line C\n");
}

void	check_li(t_ligth li)
{

	if (li.bri < 0.0 || li.bri > 1.0)
		ft_msg_err("Error Line L\n");
}

void	check_pl(t_plane *p)
{
	if (p->vec_orien.x < -1.0 || p->vec_orien.x > 1.0)
		ft_msg_err("Error Line PL\n");
	if (p->vec_orien.y < -1.0 || p->vec_orien.y > 1.0)
		ft_msg_err("Error Line PL\n");
	if (p->vec_orien.z < -1.0 || p->vec_orien.z > 1.0)
		ft_msg_err("Error Line PL\n");
}

