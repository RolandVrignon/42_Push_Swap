# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:22:30 by rvrignon          #+#    #+#              #
#    Updated: 2022/06/02 18:26:25 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  	push_swap.c initialize.c  initialize_two.c free.c swap_utils_one.c \
		swap_utils_two.c swap_utils_three.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	push_swap.a

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