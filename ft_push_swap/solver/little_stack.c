/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:47:25 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/23 01:00:14 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	solve_trio(t_board *board)
{
	t_stack	*a;

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

static void	solve_five(t_board *board)
{
	t_stack	*a;
	int		i;

	i = 0;
	while (i < 6)
	{
		a = board->a;
		if (a->content->rank == 3 || a->content->rank == 4)
			swap_pb(board);
		else
			swap_ra(board);
		i++;
	}
	solve_trio(board);
	if (board->b->content->rank == 3)
		swap_sb(board);
	swap_pa(board);
	swap_pa(board);
	swap_ra(board);
	swap_ra(board);
}

void	little_stack_solver(t_board *board)
{
	int	size;

	size = lstsize(board->a);
	if (size == 2)
		swap_sa(board);
	else if (size == 3)
		solve_trio(board);
	else if (size == 5)
		solve_five(board);
	else
		ft_printf("Not enough numbers\n");
}
