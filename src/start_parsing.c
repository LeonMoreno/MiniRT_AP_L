#include "miniRT.h"

int	ft_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*get_bool(char *line, double *al_ratio)
{
	double res;
	double fact;

	*al_ratio = 0;
	res = 0;
	fact = 1;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	while (ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			fact = 0.1;
		if (ft_isdigit(*line))
			res = (res * 10.0f) + (*line - 48);
		line++;
	}
	*al_ratio = res * fact;
	return (*(&line));
}

char	*get_int(char *line, unsigned char *r)
{
	int	res;

	*r = 0;
	res = 0;
	while (ft_whitespace(*line) || *line == '+')
		line++;
	while (ft_isdigit(*line))
	{
		res = (res * 10) + (*line - 48);
		line++;
	}
	++line;
	*r = res;
	return (*(&line));
}

t_al	init_struc_al(char *line)
{
	int		i;
	t_al 	al;

	i = 0;
	al.id = AL;
	line++;
	line = get_bool(line, &al.al_ratio);
	line = get_int(line, &al.rgb.r);
	line = get_int(line, &al.rgb.g);
	line = get_int(line, &al.rgb.b);
	printf("al_Ratio = %f\n", al.al_ratio);
	printf("__R = %d\n", al.rgb.r);
	printf("__g = %d\n", al.rgb.g);
	printf("__B = %d\n", al.rgb.b);
	printf("line = %s\n", line);
	return (al);
}

void	line_parser(char *line, t_mini *m)
{
//	printf("line = %s", line);
	if (!ft_strncmp(line, "A", 1))
			m->ele.al = init_struc_al(line);
}
