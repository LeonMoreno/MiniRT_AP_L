#include "miniRT.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bits_pp / 8));
	*(unsigned int*)dst = color;
}

