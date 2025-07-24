#include "get_next_line.h" // Include your GNL header
#include <fcntl.h>        // For open()
#include <stdio.h>        // For printf()

int main(void)
{
    int     fd;
    char    *line;
    int     count = 1;

    // Open a test file (create 'test.txt' with some lines for testing)
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    printf("Reading from file descriptor %d:\n", fd);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Line already includes '\n'
        free(line); // IMPORTANT: Free the allocated memory after use
        count++;
    }
    // After loop, line will be NULL (EOF or error occurred)
    if (line == NULL && count == 1) // If no lines were read at all
        printf("No lines read or an error occurred.\n");
    else if (line == NULL) // If lines were read, but now it's EOF
        printf("End of file reached.\n");

    close(fd); // Close the file descriptor
    return (0);
}
