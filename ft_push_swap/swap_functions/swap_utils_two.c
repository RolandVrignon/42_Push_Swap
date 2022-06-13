/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:37 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 17:14:36 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ra(t_board *board)
{
	t_stack		*a;
	t_content	*content;

	ft_printf("ra\n");
	if (!board->a)
		return ;
	a = board->a;
	if (!a->next)
		return ;
	board->a = board->a->next;
	board->a->prev = NULL;
	content = a->content;
	free(a);
	a = board->a;
	while (a->next != NULL)
		a = a->next;
	list_add_back(a, content);
}

void	swap_rb(t_board *board)
{
	t_stack		*b;
	t_content	*content;

	ft_printf("rb\n");
	if (!board->b)
		return ;
	b = board->b;
	if (!b->next)
		return ;
	board->b = board->b->next;
	board->b->prev = NULL;
	content = b->content;
	free(b);
	b = board->b;
	while (b->next != NULL)
		b = b->next;
	list_add_back(b, content);
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
