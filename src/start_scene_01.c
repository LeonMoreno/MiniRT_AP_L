#include "miniRT.h"

/*void	start_camera(t_mini *m)
{
	double	viewport_h;
	double	viewport_w;
	double	focal_length;
	t_vec	res_1;
	t_vec	res_2;

	viewport_h = 2.0;
	viewport_w = m->aspe_ratio * viewport_h;
	focal_length = 1.0;

	m->camera.origi = new_vec(0, 0, 8.0);
	m->camera.horizo = new_vec(viewport_w, 0, 0);
	m->camera.verti = new_vec(0, viewport_h, 0);
	res_1 = vec_minus(m->camera.origi, vec_divi(m->camera.horizo, 2));
	res_2 = vec_minus(vec_divi(m->camera.verti, 2), new_vec(0, 0, focal_length));
	m->camera.ll_corner = vec_minus(res_1, res_2);

}*/

void	start_resolution(t_mini *m)
{
	m->aspe_ratio = 16.0 / 9.0;
	m->w_win = 1920;
	m->h_win = (int) m->w_win / m->aspe_ratio;
	printf("h = %d\n", m->h_win);
}
