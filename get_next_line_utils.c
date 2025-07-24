#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*find_newline(char *stash)
{
	if (!stash)
		return (NULL);

	while (*stash != '\0')
	{
		if (*stash == '\n')
			return ((char *)stash);
		stash++;
	}
	return (NULL);
}

char	*join_strings(char *stash, char *buffer)
{
	char	*new_str;
	int	i;
	int	j;

	if (stash == NULL)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	new_str = malloc(ft_strlen(buffer) + ft_strlen(stash) + 1);
	if (!new_str)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i])
	{
		new_str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(stash);
	return (new_str);
}

char	*extract_line(char *stash)
{
	char	*line;
	char	*newline_pos;
	int	line_len;
	int	i;

	// If NULL or empty there is no line to return
	if (!stash || !*stash)
		return (NULL);
	// Find new line
	newline_pos = find_newline(stash);
	if (newline_pos == NULL)
		line_len = ft_strlen(stash);
	else
		line_len = (newline_pos - stash) + 1;
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*leftovers;
	char	*newline_pos;
	int	i;

	newline_pos = find_newline(stash);
	if (!newline_pos)
	{
		free(stash);
		return(NULL);
	}
	leftovers = malloc(ft_strlen(newline_pos + 1) + 1);
	if (!leftovers)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (*(newline_pos + 1 + i))
	{
		leftovers[i] = *(newline_pos + 1 + i);
		i++;
	}
	leftovers[i] = '\0';
	free(stash);
	return (leftovers);
}

