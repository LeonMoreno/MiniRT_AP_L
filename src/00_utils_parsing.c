/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:31:19 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/06 14:31:20 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*str_to(char *line, int *res, double *fact)
{
	int	ctrl;

	ctrl = 0;
	while (*line && !ft_whitespace(*line) && *line != '.' && *line != ',')
	{
		*fact = *fact * 10;
		if (ft_isdigit(*line))
		{
			*res = (*res * 10) + (*line - 48);
			ctrl = 1;
		}
		else if (!ft_isdigit(*line) && *line != '.' && *line != ',')
			ft_msg_err("Error in file\n");
		line++;
	}
	if (!ctrl)
		ft_msg_err("Un argument is missing\n");
	return (*(&line));
}

char	*move_str(char *line, int *sing)
{
	*sing = 1;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	if (*line == '-')
	{
		*sing = -1;
		line++;
	}
	return (*(&line));
}

char	*get_doub(char *line, double *al_ratio)
{
	int		res;
	int		sing;
	double	fact;

	fact = 1;
	*al_ratio = 0;
	res = 0;
	line = move_str(line, &sing);
	line = str_to(line, &res, &fact);
	if (*line == '.')
	{
		line++;
		fact = 1;
		line = str_to(line, &res, &fact);
	}
	else
	{
		*al_ratio = ((double)res * sing);
		line++;
		return (*(&line));
	}
	*al_ratio = ((double)res * sing) / fact;
	if (*line == ',')
		line++;
	return (*(&line));
}

char	*get_int(char *line, unsigned char *r, bool b)
{
	int		res;
	int		sing;
	double	fact;

	sing = 1;
	*r = 0;
	res = 0;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	if (*line == '-')
	{
		sing = -1;
		line++;
	}
	line = str_to(line, &res, &fact);
	if (*line == ',')
		++line;
	if (b == true)
		check_rgb(res * sing);
	*r = res * sing;
	return (*(&line));
}
