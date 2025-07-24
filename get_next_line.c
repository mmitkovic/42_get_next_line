#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int		byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (find_newline(stash) == NULL && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(stash);
			free(buffer);
			stash = NULL;
			return (NULL);
		}
		if (byte_read > 0)
		{
			buffer[byte_read] = '\0';
			stash = join_strings(stash, buffer);
		}
	}
	free(buffer);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}

