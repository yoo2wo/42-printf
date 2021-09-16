SRCS		=	ft_printf.c\
				ft_printf_utils.c\
				ft_printf_utils_2.c\
				ft_get_arg.c\
				ft_get_arg_2.c\
				ft_printf_arg_utils.c\
				ft_set_format.c

SRCS_BONUS	=	ft_printf_bonus.c\
				ft_printf_utils_bonus.c\
				ft_printf_utils_2_bonus.c\
				ft_get_arg_bonus.c\
				ft_get_arg_2_bonus.c\
				ft_printf_arg_utils_bonus.c\
				ft_set_format_bonus.c

CC			=	gcc
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
NAME		=	libftprintf.a
HEADER		=	-I .
CFLAG		=	-Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	ar -rc $(NAME) $^

bonus		:	$(OBJS_BONUS)
	ar -rc $(NAME) $^

%.o			:	%.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean		:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
