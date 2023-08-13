#include <unistd.h>
#include <fcntl.h>
#include "my_ft.h"
#include "utilis.h"

int main(int argc, char **argv)
{
    int fd;
    int len;
    char *path;

    if (argc < 3)
    {
        my_putstr("EXPECTED --> /PATH -- STRING");
        return (1);
    }
    path = argv[1];
    fd = open(path, O_RDWR);
    if (fd == -1)
    {
        my_putstr("Error while opening the file ");
        return 1;
    }
    len = my_strlen(argv[2]);
    
    if (!end_of_file(fd))
    {   
        write(fd, "\n", 1);
        write(fd, argv[2], len);
    }
    close(fd);

    return (0);
}