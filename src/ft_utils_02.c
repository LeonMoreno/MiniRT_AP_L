#include "miniRT.h"

void	ft_free_cy(t_cyli *c)
{
	t_cyli	*t;
	t_cyli	*f;

	t = c;
	while (t)
	{
		f = t;
		t = t->next;
		free (f);
	}
}
