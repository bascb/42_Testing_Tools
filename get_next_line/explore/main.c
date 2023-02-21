#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    char    *rc;
    int     fd;

    if (argc < 2)
    {
        printf("Need path to file!\n");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    while ((rc = get_next_line(fd)) != NULL)
    {
        printf("%s", rc);
        free(rc);
    }
    close(fd);
    return (0);    
}