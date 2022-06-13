/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:31:37 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 17:35:25 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_move_rra(t_board *board)
{
	t_stack		*a;
	t_content	*content;

	if (!board->a)
		return ;
	a = board->a->next;
	if (!a)
		return ;
	while (a->next != NULL)
		a = a->next;
	content = a->content;
	a->prev->next = NULL;
	free(a);
	board->a = list_add_front(board->a, content);
}

void	swap_move_rrb(t_board *board)
{
	t_stack		*b;
	t_content	*content;

	if (!board->b)
		return ;
	b = board->b->next;
	if (!b)
		return ;
	while (b->next != NULL)
		b = b->next;
	content = b->content;
	b->prev->next = NULL;
	free(b);
	board->b = list_add_front(board->b, content);
}
