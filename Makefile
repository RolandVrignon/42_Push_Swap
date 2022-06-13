# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:22:30 by rvrignon          #+#    #+#              #
#    Updated: 2022/06/13 21:13:53 by rvrignon         ###   ########.fr        #
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
		ft_push_swap/swap_functions/swap_utils_four.c \
		ft_push_swap/swap_functions/swap_utils_five.c \
		ft_push_swap/solver/check.c \
		ft_push_swap/solver/big_stack.c \
		ft_push_swap/solver/little_stack.c \

SRC_CHECKER = 	ft_checker/main.c \
				ft_checker/initialize/initialize.c \
				ft_checker/initialize/initialize_two.c \
				ft_checker/initialize/initialize_three.c \
				ft_checker/initialize/free.c \
				ft_checker/swap_functions/swap_utils_one.c \
				ft_checker/swap_functions/swap_utils_two.c \
				ft_checker/swap_functions/swap_utils_three.c \
				ft_checker/swap_functions/swap_utils_four.c \
				ft_checker/swap_functions/swap_utils_five.c \
				ft_checker/checker/check.c \
				ft_checker/checker/get_next_line.c \
				ft_checker/checker/get_next_line_utils.c \

OBJ		=	$(SRC:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	ft_push_swap/push_swap.a

NAME_CHECKER = ft_checker/checker.a

PROG	=	push_swap

PROG_CHECKER = checker

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)
			$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(NAME)
			
bonus :		$(OBJ_CHECKER)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME_CHECKER)
			ar rcs $(NAME_CHECKER) $(OBJ_CHECKER)
			$(CC) $(CFLAGS) -o $(PROG_CHECKER) $(SRC_CHECKER) $(NAME_CHECKER)

clean:		
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME_CHECKER) $(NAME) $(OBJ) $(OBJ_CHECKER)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(PROG) $(PROG_CHECKER)

re:			fclean $(NAME) $(NAME_CHECKER)

.PHONY:		all clean fclean re