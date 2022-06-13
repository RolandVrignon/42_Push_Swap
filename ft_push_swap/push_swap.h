/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:20 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 14:25:22 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_content
{
	long int		nb;
	int				rank;
}	t_content;

typedef struct s_stack
{
	struct s_content	*content;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

typedef struct s_board
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_board;

// INITIALISATION FUNCTIONS

int				error(void);

int				check_av(char **av, int start);

t_stack			*create_list(t_content *content);

t_stack			*list_add_back(t_stack *prev_stack, t_content *content);

t_stack			*list_add_front(t_stack *first_stack, t_content *content);

int				lstsize(t_stack *lst);

t_board			*push_swap(t_board *board, char **av, int start);

int				check_duplicates(t_board *board);

t_board			*create_board(t_board *board, char **av, int start);

void			print_stack(t_stack *stack);

void			get_rank(t_stack *stack);

t_content		*create_content(long int nb);

// FREE FUNCTIONS

void			free_stack(t_stack *stack);

void			free_board(t_board *board);

void			free_split(char **tab);

// SWAP FUNCTIONS

void			swap_sa(t_board *board);

void			swap_sb(t_board *board);

void			swap_ss(t_board *board);

void			swap_pa(t_board *board);

void			swap_pb(t_board *board);

void			swap_ra(t_board *board);

void			swap_rb(t_board *board);

void			swap_rr(t_board *board);

void			swap_rra(t_board *board);

void			swap_rrb(t_board *board);

void			swap_rrr(t_board *board);

// SOLVER FUNCTIONS

int				check_stack(t_stack *stack);

void			little_stack_solver(t_board *board);

void			big_stack_solver(t_board *board);

#endif