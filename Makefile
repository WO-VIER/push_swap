NAME = push_swap
CC = gcc
CFLAGS = -g #-Wall -Wextra -Werror


# Sources ls -1 *.c
SRCS = create_list.c \
double_linked_list.c \
double_linked_list_util.c \
error_util.c \
move_sort.c \
node_routine.c \
push.c \
push_swap.c \
radix.c \
rotate.c \
rrotate.c \
swap.c \
util.c \
vue.c

# Objects
OBJS = $(SRCS:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
debug: CFLAGS += -g -fsanitize=address
debug: all
sanitize: CFLAGS += -g -fsanitize=address
sanitize: $(LIBFT) $(NAME)

sanitize-no-flags: CFLAGS = -g -fsanitize=address
sanitize-no-flags: $(LIBFT) $(NAME)


re-sanitize: fclean sanitize

re-sanitize-no-flags: fclean sanitize-no-flags

.PHONY: all clean fclean re debug sanitize sanitize-no-flags re-sanitize re-sanitize-no-flags
