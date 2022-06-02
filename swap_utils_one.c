/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:32 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 16:42:42 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_sa(t_board *board)
{
	t_stack		*a_one;
	t_stack		*a_two;
	long int	swap;

	a_one = board->a;
	if (!a_one)
		return ;
	a_two = a_one->next;
	if (!a_two)
		return ;
	swap = a_one->nb;
	a_one->nb = a_two->nb;
	a_two->nb = swap;
	ft_printf("sa\n");
}

void    swap_sb(t_board *board)
{
	t_stack		*b_one;
	t_stack		*b_two;
	long int	swap;

	b_one = board->b;
	if (!b_one)
		return ;
	b_two = b_one->next;
	if (!b_two)
		return ;
	swap = b_one->nb;
	b_one->nb = b_two->nb;
	b_two->nb = swap;
	ft_printf("sb\n");
}

void	swap_ss(t_board *board)
{
	swap_sa(board);
	swap_sb(board);
	ft_printf("ss\n");
}

void	swap_pa(t_board *board)
{
	t_stack *a;
	t_stack	*b;
	t_stack *tmp;

	b = board->b;
	a = board->a;
	if (!b)
		return ;
	if (!a)
		board->a = create_list(b->nb);
	else
	{
		tmp = (t_stack*)malloc(sizeof(t_stack));
		if (!tmp)
			return ;
		tmp->next = a;
		a->prev = tmp;
		tmp->prev = NULL;
		tmp->nb = b->nb;
		board->a = tmp;
	}
	tmp = b->next;
	if (!tmp)
		return ;
	tmp->prev = NULL;
	free(b);
	board->b = tmp;
	ft_printf("pa\n");
}

void	swap_pb(t_board *board)
{
	t_stack *a;
	t_stack	*b;
	t_stack *tmp;

	a = board->a;
	b = board->b;
	if (!a)
		return ;
	if (!b)
		board->b = create_list(a->nb);
	else
	{
		tmp = (t_stack*)malloc(sizeof(t_stack));
		if (!tmp)
			return ;
		tmp->next = b;
		b->prev = tmp;
		tmp->prev = NULL;
		tmp->nb = a->nb;
		board->b = tmp;
	}
	tmp = a->next;
	if (!tmp)
		return ;
	tmp->prev = NULL;
	free(a);
	board->a = tmp;
	ft_printf("pb\n");
}

