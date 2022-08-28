#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*s = "0.00020";
	double res;
	double d;
	int	i;

	res = 1 * 10;
	d = 1;
	i = 0;

	while (i < 7)
	{
		d *= 10.;
		i++;
	}
	printf("res = %f\n", res);
	
	res = 2 * 10;
	res = res / d;
	printf("res = %f  d = %f \n", res, d);
	printf("Atof = %f \n", atof(s));
	
	return (0);
}
