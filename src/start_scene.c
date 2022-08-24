#include "miniRT.h"

void	start_gnl(int fd, t_mini *m)
{
	char	*line;

	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	while (line)
	{
		line = get_next_line(fd);
		if (line && line[0] != '\n')
			line_parser(line, m);
		if (line)
			free(line);
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
	res = ft_split(argv[1], '.');
	if (ft_strncmp(res[1], "rt", 2))
		ft_msg_err("Bad file extension\n");
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
	if (valide_argu(argc, argv))
		fd = ft_open_file(argv[1]);
	if (fd > 0)
		start_gnl(fd, m);
	start_resolution(m);
	//start_camera(m);
}
