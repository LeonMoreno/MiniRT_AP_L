#include "miniRT.h"

int	ft_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*get_bool(char *line, double *al_ratio)
{
	double 	res;
	double	fact;
	int		sing;

	sing = 1;
	*al_ratio = 0;
	res = 0;
	fact = 1;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	if (*line == '-')
		{
			sing = -1;
			line++;
		}
	while (ft_isdigit(*line) || *line == '.')
	{
		printf("while = %c\n", *line);
		if (*line == '.')
			fact = 0.1;
		if (ft_isdigit(*line))
			res = (res * 10.0f) + (*line - 48);
		line++;
	}
	*al_ratio = res * fact * sing;
	if (*line == ',')
		line++;
	return (*(&line));
}

char	*get_int(char *line, unsigned char *r)
{
	int	res;

	*r = 0;
	res = 0;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	while (*line && *line != '\n' && res != -7)
	{
		if (ft_isdigit(*line))
			res = (res * 10) + (*line - 48);
		else if (!ft_isdigit(*line) && *line != ',')
			res = -7;
		else if (*line == ',')
			break ;
		line++;
	}
	if (res == -7)
		ft_msg_err("Error in file\n");
	++line;
	*r = res;
	return (*(&line));
}
