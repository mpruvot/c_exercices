#include "utilis.h"
#include "my_ft.h"
#include <unistd.h>


// Return 0 if it is the end of the file 
int print_file(int fd)
{
    char buff[256];
    int ret;
    int i;

    ret = read(fd, buff, sizeof(buff));
    i = 0;

    if (ret == 0)
        return (1);
    
    while (ret > 0)
    {
        i = 0;
        while (i < ret)
        {
            my_putchar(buff[i]);
            i++;
        }
        ret = read(fd, buff, sizeof(buff));
    }
    buff[i] = '\n';
    return ret;
}