#include <unistd.h>
#include <fcntl.h>
#include "my_ft.h"

int main()
{
    int fd;
    int ret;
    char buff[256];
    int i;

    fd = open("main.c", O_RDONLY);
    ret = read(fd, buff, sizeof(buff));

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
    
    close(fd);
    return (0);

}