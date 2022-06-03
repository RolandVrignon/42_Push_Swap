/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:35 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/03 14:48:33 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	util_pb(t_board *board, t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!a)
		return ;
	if (!b)
		board->b = create_list(a->nb);
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			return ;
		tmp->next = b;
		b->prev = tmp;
		tmp->prev = NULL;
		tmp->nb = a->nb;
		board->b = tmp;
	}
}

static void	util_pa(t_board *board, t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b)
		return ;
	if (!a)
		board->a = create_list(b->nb);
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			return ;
		tmp->next = a;
		a->prev = tmp;
		tmp->prev = NULL;
		tmp->nb = b->nb;
		board->a = tmp;
	}
}

void	swap_pa(t_board *board)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	ft_printf("pa\n");
	b = board->b;
	a = board->a;
	util_pa(board, a, b);
	tmp = b->next;
	if (!tmp)
	{
		free(b);
		board->b = NULL;
		return ;
	}
	tmp->prev = NULL;
	free(b);
	board->b = tmp;
}

void	swap_pb(t_board *board)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	ft_printf("pb\n");
	a = board->a;
	b = board->b;
	util_pb(board, a, b);
	tmp = a->next;
	if (!tmp)
		return ;
	tmp->prev = NULL;
	free(a);
	board->a = tmp;
}
