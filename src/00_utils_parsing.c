#include "miniRT.h"

int	ft_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*str_to(char *line, int *res, double *fact)
{
	while (*line && !ft_whitespace(*line) && *line != '.' && *line != ',')
	{
		*fact = *fact * 10;
		if (ft_isdigit(*line))
			*res = (*res * 10) + (*line - 48);
		else if (!ft_isdigit(*line) && *line != '.' && *line != ',')
			ft_msg_err("Error in file AQUI\n");
		line++;
	}
	return (*(&line));
}

char	*get_doub(char *line, double *al_ratio)
{
	int		res;
	int		sing;
	double fact;

	sing = 1;
	fact = 1;
	*al_ratio = 0;
	res = 0;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	if (*line == '-')
	{
		sing = -1;
		line++;
	}
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

char	*get_int(char *line, unsigned char *r)
{
	int		res;
	int		sing;
	double fact;

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
	*r = res * sing;
	return (*(&line));
}
