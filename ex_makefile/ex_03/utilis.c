#include "utilis.h"
#include <unistd.h>


// Return 0 if it is the end of the file 
int end_of_file(int fd)
{
    char buff[256];
    int ret;

    ret = read(fd, buff, sizeof(buff));
    while (ret > 0)
        ret = read(fd, buff, sizeof(buff));

    return ret;
}