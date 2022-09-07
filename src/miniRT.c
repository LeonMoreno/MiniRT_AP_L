/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:37:08 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 15:37:14 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_mini	*m;

	m = malloc(sizeof(t_mini));
	start_scene(argc, argv, m);
	ft_print_ele(m);
	mlx_start(m);
	start_render(m);
	mlx_loop(m->mlx);
	ft_free(m);
	return (0);
}
