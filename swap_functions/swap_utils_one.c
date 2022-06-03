/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/03 14:40:09 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_sa(t_board *board)
{
	t_stack		*a_one;
	t_stack		*a_two;
	long int	swap;

	ft_printf("sa\n");
	a_one = board->a;
	if (!a_one)
		return ;
	a_two = a_one->next;
	if (!a_two)
		return ;
	swap = a_one->nb;
	a_one->nb = a_two->nb;
	a_two->nb = swap;
}

void	swap_sb(t_board *board)
{
	t_stack		*b_one;
	t_stack		*b_two;
	long int	swap;

	ft_printf("sb\n");
	b_one = board->b;
	if (!b_one)
		return ;
	b_two = b_one->next;
	if (!b_two)
		return ;
	swap = b_one->nb;
	b_one->nb = b_two->nb;
	b_two->nb = swap;
}

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
