/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:47 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/06 14:31:48 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_msg_err(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(1);
}

void	ft_free_arr2(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_sp(t_sphere *s)
{
	t_sphere	*t;
	t_sphere	*f;

	t = s;
	while (t)
	{
		f = t;
		t = t->next;
		free(f);
	}
}

void	ft_free_pl(t_plane *s)
{
	t_plane	*t;
	t_plane	*f;

	t = s;
	while (t)
	{
		f = t;
		t = t->next;
		free(f);
	}
}

void	ft_free(t_mini *m)
{
	ft_free_sp(m->ele.head_sp);
	ft_free_pl(m->ele.head_pl);
	ft_free_cy(m->ele.head_cy);
	free(m);
}
