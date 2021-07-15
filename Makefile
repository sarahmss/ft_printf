NAME = libftprintf.a

SRCS_DIR = ./sources/

LIBFT_DIR = ./libraries/libft/

LIBFT = libft.a

INCLUDES = /includes

SRCS =	ft_printf.c				\
		ft_eval_format.c		\
		ft_printstr.c			\
		ft_printchar.c			\
		ft_printint.c			\
		ft_printhex.c			\
		ft_flags.c				\
		ft_precision.c			\
		ft_width.c				\
		ft_padzero.c			\

SRCS_OBJS = $(SRCS:.c=.o)

CC = gcc

C_FLAGS = -c -Wall -Werror -Wextra

LIBFT_OBJS = $(LIBFT_DIR)*.o

all:		$(NAME)

bonus:		all

$(NAME):	$(SRCS_OBJS)
			@make -C $(LIBFT_DIR)
			@$(CC) $(C_FLAGS) $(SRCS)
			@ar -rcs $(NAME) $(SRCS_OBJS) $(LIBFT_OBJS)
clean :
		@make clean -C $(LIBFT_DIR)
		@rm -rf $(SRCS_OBJS)

fclean:		clean
		@make clean -C $(LIBFT_DIR)
		@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
