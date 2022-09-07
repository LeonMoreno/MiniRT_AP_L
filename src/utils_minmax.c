/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:03:34 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/07 14:03:36 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	min(double num1, double num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

double	max(double num1, double num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}
