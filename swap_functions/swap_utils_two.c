/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:37 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/03 14:48:59 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ra(t_board *board)
{
	t_stack		*a;
	long int	nb;

	ft_printf("ra\n");
	if (!board->a)
		return ;
	a = board->a;
	if (!a->next)
		return ;
	board->a = board->a->next;
	board->a->prev = NULL;
	nb = a->nb;
	free(a);
	a = board->a;
	while (a->next != NULL)
		a = a->next;
	list_add_back(a, nb);
}

void	swap_rb(t_board *board)
{
	t_stack		*b;
	long int	nb;

	ft_printf("rb\n");
	if (!board->b)
		return ;
	b = board->b;
	if (!b->next)
		return ;
	board->b = board->b->next;
	board->b->prev = NULL;
	nb = b->nb;
	free(b);
	b = board->b;
	while (b->next != NULL)
		b = b->next;
	list_add_back(b, nb);
}

void	swap_rr(t_board *board)
{
	ft_printf("rr\n");
	swap_ra(board);
	swap_rb(board);
}

void	swap_ss(t_board *board)
{
	ft_printf("ss\n");
	swap_sa(board);
	swap_sb(board);
}
