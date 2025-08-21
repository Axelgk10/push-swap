NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -I -I$(LIBFT_DIR)

LIBFT_DIR = libft
LIBFT = libft/libft.a
LIBFT_SRCS = $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_isalnum.c \
        $(LIBFT_DIR)/ft_isascii.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_toupper.c \
        $(LIBFT_DIR)/ft_tolower.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_memset.c \
        $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c \
        $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strlcat.c $(LIBFT_DIR)/ft_strchr.c \
        $(LIBFT_DIR)/ft_strrchr.c $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_memchr.c \
        $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/ft_atoi.c \
        $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_substr.c \
        $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strtrim.c $(LIBFT_DIR)/ft_split.c \
        $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_striteri.c \
        $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_putendl_fd.c \
        $(LIBFT_DIR)/ft_putnbr_fd.c \
		$(LIBFT_DIR)/printf/ft_print_char.c $(LIBFT_DIR)/printf/ft_print_hex_lower.c \
		$(LIBFT_DIR)/printf/ft_print_hex_upper.c $(LIBFT_DIR)/printf/ft_print_nbr.c \
		$(LIBFT_DIR)/printf/ft_print_percent.c $(LIBFT_DIR)/printf/ft_print_ptr.c \
		$(LIBFT_DIR)/printf/ft_print_str.c $(LIBFT_DIR)/printf/ft_print_unsigned.c $(LIBFT_DIR)/printf/ft_printf.c \

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/operations.c \
		$(SRCS_DIR)/parsing.c \
		$(SRCS_DIR)/parsing2.c \
		$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/utils.c \
		$(SRCS_DIR)/errors.c \
		$(SRCS_DIR)/algorithms.c \
		$(SRCS_DIR)/algorithms2.c \

OBJS_DIR = objs
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	make -C libft fclean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
