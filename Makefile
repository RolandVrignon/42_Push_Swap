# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:22:30 by rvrignon          #+#    #+#              #
#    Updated: 2022/06/13 14:32:01 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  	ft_push_swap/main.c \
		ft_push_swap/initialize/initialize.c \
		ft_push_swap/initialize/initialize_two.c \
		ft_push_swap/initialize/initialize_three.c \
		ft_push_swap/initialize/free.c \
		ft_push_swap/swap_functions/swap_utils_one.c \
		ft_push_swap/swap_functions/swap_utils_two.c \
		ft_push_swap/swap_functions/swap_utils_three.c \
		ft_push_swap/solver/check.c \
		ft_push_swap/solver/big_stack.c \
		ft_push_swap/solver/little_stack.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	ft_push_swap/push_swap.a

PROG	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)
			$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(NAME)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) $(PROG)

re:			fclean $(NAME)

.PHONY:		all clean fclean re