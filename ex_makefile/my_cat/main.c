#include <unistd.h>
#include <fcntl.h>
#include "my_ft.h"
#include "utilis.h"

int main(int argc, char **argv)
{
    int fd;
    char *path;

    if (argc < 2)
    {
        my_putstr("EXPECTED --> /FILE PATH");
        return (1);
    }

    path = argv[1];
    fd = open(path, O_RDONLY);
    if (fd == -1)
        my_putstr("Error while opening the file ");
    
    print_file(fd);
    return (0);
}