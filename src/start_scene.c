/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:33:31 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/08 13:26:32 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_line_requi(t_mini *m)
{
	if (m->a != true)
		m->ele.al = init_struc_al("A 0.1 255,255,255", m);
	if (m->c != true)
		m->ele.ca = init_struc_camera("C 0,0,90 0,0,0 70", m);
	if (m->l != true)
		m->ele.li = init_struc_light("L -25,-27,95 0.8", m);
	// if (m->pl != true)
	// {
	// 	init_struc_plane("pl -50,0,0 		1,0,0	    	0,0,0", m);
	// 	init_struc_plane("pl 50,0,0 		1,0,0	    	0,0,0", m);
	// }
}

void	start_gnl(int fd, t_mini *m)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line && line[0] != '\n')
			line_parser(line, m);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

int	ft_open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_msg_err("Err open File\n");
	return (fd);
}

int	valide_argu(int argc, char **argv)
{
	char	**res;

	if (argc != 2)
		ft_msg_err("Bad No ARGUS\n");
	if (!ft_strrchr(argv[1], '.'))
		ft_msg_err("First arg must be a '*.rt' file\n");
	res = ft_split(argv[1], '.');
	if (ft_strncmp(res[1], "rt", 2))
	{
		ft_free_arr2(res);
		ft_msg_err("Bad file extension\n");
	}
	ft_free_arr2(res);
	return (1);
}

void	start_scene(int argc, char **argv, t_mini *m)
{
	int	fd;

	fd = 0;
	m->ele.head_sp = NULL;
	m->ele.head_pl = NULL;
	m->ele.head_cy = NULL;
	m->a = false;
	m->c = false;
	m->l = false;
	m->pl = false;
	m->ob = NULL;
	if (valide_argu(argc, argv))
		fd = ft_open_file(argv[1]);
	if (fd > 0)
		start_gnl(fd, m);
	check_line_requi(m);
	start_resolution(m);
}
