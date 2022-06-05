/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:46:52 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/05 13:37:45 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned int	solve_init(t_board *board)
{
	unsigned int	steps;

	steps = 0;
	if (board->a->nb > board->a->next->nb)
	{
		swap_sa(board);
		steps = 1;
	}
	return (steps);
}

unsigned int	solve_compare_a(t_board *board)
{
	t_stack *a;
	unsigned int	steps;

	a = board->a;
	steps = 0;
	while (a->next != NULL)
	{
		if (a->next != NULL && a->nb < a->next->nb)
		{
			swap_ra(board);
			a = board->a;
			steps = steps + 1;
		}
		else
		{
			swap_pb(board);
			steps = steps + 1;
		}
		a = a->next;
	}
	return (steps);
} 

unsigned int	solve_compare_b(t_board *board)
{
	t_stack *b;
	unsigned int	steps;

	steps = 0;
	b = board->b;
	while (b->next != NULL)
	{
		if (b->next != NULL && b->nb < b->next->nb)
		{
			swap_rb(board);
			steps = steps + 1;
			b = board->b;
		}
		else
		{
			swap_pa(board);
			steps = steps + 1;
		}
		b = b->next;
	}
	return (steps);
} 

unsigned int	solve_main(t_board *board)
{
	unsigned int	steps;
	
	steps = 0;
	steps = steps + solve_init(board);
	while(steps < 5)
	{
		steps = steps + solve_compare_a(board);
		steps = steps + solve_compare_b(board);
	}
	return (steps);
}