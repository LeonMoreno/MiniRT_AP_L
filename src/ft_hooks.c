/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:36 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/14 16:30:39 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_close(void)
{
	exit(0);
}

/**
 * @brief: control de los eventos de teclado
 * printf("key = %d\n", keyhook);
 * @param keyhook: tecla presionada
 */
int	ft_key_hook(int keyhook, t_mini *m)
{
	if (keyhook == 53)
		ft_close();
	if (keyhook == 35)
		ft_print_ele(m);
	event_sp(m, keyhook);
	event_cy(m, keyhook);
	event_pl(m, keyhook);
	event_ca(m, keyhook);
	event_li(m, keyhook);
	printf("key = %d\n", keyhook);
	return (0);
}

void	ray_gen(int x, int y, t_mini *m)
{
	t_inter	cli;

	m->ob = NULL;
	cli = camera_ray(m, y, x);
	if (cli.hit)
		m->ob = (t_sphere *) cli.obj;
	if (m->ob && m->ob->id == SP)
	{
		m->e_sp = (t_sphere *) cli.obj;
		m->e_pl = NULL;
		m->e_cy = NULL;
	}
	else if (m->ob && m->ob->id == PL)
	{
		m->e_pl = (t_plane *) cli.obj;
		m->e_sp = NULL;
		m->e_cy = NULL;
	}
	else if (m->ob && m->ob->id == CY)
	{
		m->e_cy = (t_cyli *) cli.obj;
		m->e_sp = NULL;
		m->e_pl = NULL;
	}
}

int	mouse_cli(int b, int x, int y, t_mini *m)
{
	if (b == 1)
		ray_gen(x, y, m);
	if (m->ob && (b == 1 && m->ob->id == SP))
		printf("Click sphere %d \n", m->e_sp->num);
	if (m->ob && (b == 1 && m->ob->id == PL))
		printf("Click Plane\n");
	if (m->ob && (b == 1 && m->ob->id == CY))
		printf("Click Cylinder\n");
	event_sp(m, b);
	return (0);
}

void	start_hooks(t_mini *m)
{
	m->e_sp = NULL;
	m->e_pl = NULL;
	mlx_hook(m->win, 17, 0, ft_close, 0);
	mlx_key_hook(m->win, ft_key_hook, m);
	mlx_mouse_hook(m->win, mouse_cli, m);
}
