
#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[700000];
	static int	buffer_reading;
	static int	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_reading)
		{
			buffer_reading = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_reading <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos++];
		if (line[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("res[%d] = [%s]\n", i++, line);
		free(line);
	}
}
