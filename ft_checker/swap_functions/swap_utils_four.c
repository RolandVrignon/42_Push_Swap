/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:29:07 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 17:35:28 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_move_sa(t_board *board)
{
	t_stack		*a_one;
	t_stack		*a_two;
	t_content	*swap;

	a_one = board->a;
	if (!a_one)
		return ;
	a_two = a_one->next;
	if (!a_two)
		return ;
	swap = a_one->content;
	a_one->content = a_two->content;
	a_two->content = swap;
}

void	swap_move_sb(t_board *board)
{
	t_stack		*b_one;
	t_stack		*b_two;
	t_content	*swap;

	b_one = board->b;
	if (!b_one)
		return ;
	b_two = b_one->next;
	if (!b_two)
		return ;
	swap = b_one->content;
	b_one->content = b_two->content;
	b_two->content = swap;
}

void	swap_move_ra(t_board *board)
{
	t_stack		*a;
	t_content	*content;

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

void	swap_move_rb(t_board *board)
{
	t_stack		*b;
	t_content	*content;

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
