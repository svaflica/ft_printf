NAME = libftprintf.a

SRC = src/ft_atoi.c src/ft_itoa_base.c src/ft_itoa.c src/ft_num_dig.c \
src/ft_percent.c src/ft_printf.c src/ft_param/ft_param_add.c \
src/ft_param/ft_param_nul.c src/ft_str/ft_print_symb.c \
src/ft_str/ft_putchar.c src/ft_str/ft_putnbr.c src/ft_str/ft_putnstr.c \
src/ft_str/ft_putstr.c src/ft_str/ft_strchr.c src/ft_str/ft_strlen.c \
src/ft_type/ft_c.c src/ft_type/ft_o.c src/ft_type/ft_p.c \
src/ft_type/ft_s.c src/ft_type/ft_u.c src/ft_type/ft_prcnt.c src/ft_itoa_base_ll.c \
src/ft_type/ft_d.c

OBJ = $(SRC:.c=.o)

INC = ./inc

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
