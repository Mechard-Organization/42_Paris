#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*res;
	char	buffer[999999] = {0};
	char	character;
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while ((read(fd, &character, 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	if (!buffer[0])
		return (NULL);
	res = malloc(i + 1);
	i = 0;
	while (buffer[i])
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
