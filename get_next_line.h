#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);

// utils
int	ft_strlen(char *s);
char	*find_newline(char *stash);
char	*join_strings(char *stash, char *buffer);
char	*clean_stash(char *stash);
char	*extract_line(char *stash);

#endif

