/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:35 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 18:18:46 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rra(t_board *board)
{
	t_stack		*a;
	long int	nb;

	ft_printf("rra\n");
	if (!board->a)
		return ;
	a = board->a->next;
	if (!a)
		return ;
	while (a->next != NULL)
		a = a->next;
	nb = a->nb;
	a->prev->next = NULL;
	free(a);
	board->a = list_add_front(board->a, nb);
}

void	swap_rrb(t_board *board)
{
	t_stack		*b;
	long int	nb;

	ft_printf("rrb\n");
	if (!board->b)
		return ;
	b = board->b->next;
	if (!b)
		return ;
	while (b->next != NULL)
		b = b->next;
	nb = b->nb;
	b->prev->next = NULL;
	free(b);
	board->b = list_add_front(board->b, nb);
}

void	swap_rrr(t_board *board)
{
	ft_printf("rrr\n");
	swap_rra(board);
	swap_rrb(board);
}
