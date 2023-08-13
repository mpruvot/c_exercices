#include "my_ft.h"
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char **argv)
{
    int fd;

    if (argc < 2)
    {
        my_putstr("EXPECTED: NEW_FILE -- STRING (OPTIONAL)\n");
        return 1;
    }
    fd = open(argv[1],O_CREAT | O_RDWR, 0777);

    if (fd == -1)
        return(-1);
    if (argc == 3)
        write(fd,argv[2],my_strlen(argv[2]));
        
    close(fd);
    return (0);
}

