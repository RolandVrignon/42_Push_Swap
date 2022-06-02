/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:20 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 11:58:09 by rvrignon         ###   ########.fr       */
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

#endif