/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:20 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 14:37:11 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "libft/libft.h"

typedef struct s_stack
{
    long int    nb;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

typedef struct s_board
{
    struct s_stack *a;
    struct s_stack *b;
}   t_board;


int		error();

int		check_av(char **av);

t_stack	*create_list(char *str);

t_stack	*list_add(t_stack *prev_stack, char *str);

t_board	*push_swap(t_board *board, char **av);

int     check_duplicates(t_board *board);

t_board	*create_board(t_board *board, char **av);

#endif