# **************************************************************************** #
# VARIABLES

# Define the output binary name
NAME	:= count_letter

# Define the flags for the compiler
CFLAGS	:= -Wall -Wextra -Werror

# Define the C compiler to use
CC	:= gcc


# **************************************************************************** #
# SOURCES

# List the source files without extension
SRC_FILES := *.c
# Use addsuffix to generate object file names from source files
OBJ_FILES := ${SRC_FILES:.c=.o}

# List of header files
HEADERS := *.h
	
# **************************************************************************** #
# RULES

# Default rule executed
all: $(NAME)

# Rule for making the binary and indirectly the object files
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

# Rule for converting .c files to .o files
# The compiler flags are applied here
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for removing object files
clean:
	rm -f $(OBJ_FILES)

# Rule for removing object files and the binary file
fclean: clean
	rm -f $(NAME)

# Rule for re-making everything
re: fclean all

# **************************************************************************** #
# PHONY

# .PHONY tells make that these rules do not represent files
.PHONY: all clean fclean re
