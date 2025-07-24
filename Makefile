# The name of the library (the main requirement of the project).
LIB_NAME	=	get_next_line.a

# The name for our test executable program.
EXEC_NAME	=	run_test

# Compiler and flags.
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I.

# Archiver and remove commands.
AR			=	ar rcs
RM			=	rm -f

# --- Source Files ---

# List of your .c files that go into the LIBRARY.
LIB_SRCS	=	get_next_line.c get_next_line_utils.c

# List of .c files needed for the EXECUTABLE (your main test file).
TEST_SRCS	=	main.c

# Automatically generate object file names from library source files.
LIB_OBJS	=	$(LIB_SRCS:.c=.o)

# --- Rules ---

# The default rule. Typing 'make' will only build the library,
# as required by the project subject.
all: $(LIB_NAME)

# Rule to create the library file from its object files.
$(LIB_NAME): $(LIB_OBJS)
	@$(AR) $(LIB_NAME) $(LIB_OBJS)
	@echo "Library $(LIB_NAME) created successfully!"

# A NEW RULE to build and run the test executable.
# Type 'make test' to use this.
# It depends on the library being created first.
test: $(LIB_NAME)
	@$(CC) $(CFLAGS) $(TEST_SRCS) $(LIB_NAME) -o $(EXEC_NAME)
	@echo "Test executable '$(EXEC_NAME)' created."
	@echo "Running tests..."
	@./$(EXEC_NAME)

# Rule to clean up library object files.
clean:
	@$(RM) $(LIB_OBJS)
	@echo "Library object files cleaned."

# Rule to clean up everything: objects, library, and the test executable.
fclean: clean
	@$(RM) $(LIB_NAME) $(EXEC_NAME)
	@echo "Everything cleaned."

# Rule to re-compile the library from scratch.
re: fclean all

# Phony rules are commands, not files.
.PHONY: all clean fclean re test


