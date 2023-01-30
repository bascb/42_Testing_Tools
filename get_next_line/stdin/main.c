#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    char    *rc;
    
    while ((rc = get_next_line(0)) != NULL)
    {
        printf("%s", rc);
        free(rc);
    }
    return (0);    
}