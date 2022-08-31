#include "miniRT.h"

void	check_cy(t_cyli *c)
{
	if (c->vec_orien.x < -1.0 || c->vec_orien.x > 1.0)
		ft_msg_err("Error Line CY\n");
	if (c->vec_orien.y < -1.0 || c->vec_orien.y > 1.0)
		ft_msg_err("Error Line CY\n");
	if (c->vec_orien.z < -1.0 || c->vec_orien.z > 1.0)
		ft_msg_err("Error Line CY\n");
}

void	check_line_len(char *l, int x, char *s)
{
	int	len;

	len = ft_strlen(l);
	if (len > x)
		ft_msg_err(s);
}
