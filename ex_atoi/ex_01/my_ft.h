
#ifndef MY_FT_H
#define MY_FT_H
// The #ifndef, #define and #endif directives are used to prevent
// the content of this header file from being included multiple times
// in the same program.

#include <unistd.h>


typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

// Outputs a character
void my_putchar(char c);

// Calculates string length
int my_strlen(char *str);

// Outputs a string
void my_putstr(char *str);

// Outputs an integer
void my_putnbr(int nb);

// Copies one string to another
char *mystrcpy(char *dest, char *src);

// Sort an str
char *my_sort_str(char *str);

#endif // MY_FT_H
// End of the #ifndef directive. Everything between #ifndef and #endif
// will be ignored if MY_FT_H is already defined, thus preventing multiple definitions.
