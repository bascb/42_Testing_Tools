#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
    char    *rc;
    int     fd1;
    int     fd2;
    int     fd3;
    int     fd4;
    int     wfd1;
    int     wfd2;
    int     wfd3;
    int     wfd4;

    fd1 = open("several_files/1.txt", O_RDONLY);
    fd2 = open("several_files/2.txt", O_RDONLY);
    fd3 = open("several_files/3.txt", O_RDONLY);
    fd4 = open("several_files/4.txt", O_RDONLY);
    wfd1 = open("several_files/1.output", O_WRONLY | O_CREAT);
    wfd2 = open("several_files/2.output", O_WRONLY | O_CREAT);
    wfd3 = open("several_files/3.output", O_WRONLY | O_CREAT);
    wfd4 = open("several_files/4.output", O_WRONLY | O_CREAT);
    rc = get_next_line(fd1);
    write(wfd1, rc, strlen(rc));
    free(rc);
    rc = get_next_line(fd2);
    write(wfd2, rc, strlen(rc));
    free(rc);
    rc = get_next_line(fd3);
    write(wfd3, rc, strlen(rc));
    free(rc);
    rc = get_next_line(fd4);
    write(wfd4, rc, strlen(rc));
    free(rc);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(wfd1);
    close(wfd2);
    close(wfd3);
    close(wfd4);
    return (0);    
}