/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:56:58 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 01:00:15 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_stack_solver(t_board *board)
{
	t_stack		*a;
	int			i;
	int			j;
	int			size;

	i = 1;
	size = lstsize(board->a);
	while (!check_stack(board->a))
	{
		j = 0;
		while (j < size)
		{
			a = board->a;
			if ((a->content->rank & i) == i)
				swap_ra(board);
			else
				swap_pb(board);
			j++;
		}
		while (board->b)
			swap_pa(board);
		get_gap(board->a);
		i = i * 2;
	}
}
