/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:47:25 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 00:35:55 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void solve_trio(t_board *board)
{
	t_stack *a;

	a = board->a;
	if (a->content->rank == 2 && a->next->content->rank == 0)
		swap_ra(board);
	else if (a->content->rank == 2 && a->next->content->rank == 1)
	{
		swap_ra(board);
		swap_sa(board);
	}
	else if (a->content->rank == 1 && a->next->content->rank == 2)
		swap_rra(board);
	else if (a->content->rank == 1 && a->next->content->rank == 0)
		swap_sa(board);
	else if (a->content->rank == 0 && a->next->content->rank == 2)
	{
		swap_rra(board);
		swap_sa(board);
	}
}

void little_stack_solver(t_board *board)
{
	if (lstsize(board->a) == 2)
		swap_sa(board);
	else if (lstsize(board->a) == 3)
		solve_trio(board);
	else
		(void)board;
}