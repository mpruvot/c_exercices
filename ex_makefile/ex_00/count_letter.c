#include "my_ft.h"
#include "utilis.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char letter;
    int fd;
    int count;
    
    count = 0;
    
    if (argc < 3)
    {
        my_putstr("Expected: PATH -- LETTER \n");
        return (1);
    }
    letter = argv[2][0];
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    count = count_letter(fd, letter);
    my_putnbr(count);
    close(fd);
    return (0);

}
