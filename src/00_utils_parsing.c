#include "miniRT.h"

int	ft_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*str_to(char *line, int *res, double *fact)
{
	*fact = 1;
	while (*line && *line != '\n')
	{
		if (*line == '.')
			*fact = 0.1;
		if (ft_isdigit(*line))
			*res = (*res * 10) + (*line - 48);
		else if (*line == ',' || ft_whitespace(*line))
			break ;
		else if (!ft_isdigit(*line) && *line != '.' && *line != ',')
			ft_msg_err("Error in file AQUI\n");
		line++;
	}
	return (*(&line));
}

char	*get_doub(char *line, double *al_ratio)
{
	int		res;
	double	fact;
	int		sing;

	sing = 1;
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
	*al_ratio = (double)res * fact * sing;
	if (*line == ',')
		line++;
	return (*(&line));
}

char	*get_int(char *line, unsigned char *r)
{
	int		res;
	double	fact;
	int		sing;

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
