/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:33:31 by lmoreno           #+#    #+#             */
/*   Updated: 2022/09/06 14:33:32 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_line_requi(t_mini *m)
{
	if (m->a != true)
		ft_msg_err("There must be at least one line A\n");
	if (m->c != true)
		ft_msg_err("There must be at least one line C\n");
	if (m->l != true)
		ft_msg_err("There must be at least one line L\n");
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
	if (valide_argu(argc, argv))
		fd = ft_open_file(argv[1]);
	if (fd > 0)
		start_gnl(fd, m);
	check_line_requi(m);
	start_resolution(m);
}
