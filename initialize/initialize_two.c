/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:15:24 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 16:30:00 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_board	*push_swap(t_board *board, char **av, int start)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	(void)b;
	a = create_list(ft_atoi(av[start]));
	i = start + 1;
	while (av[i] != NULL)
	{
		a = list_add_back(a, ft_atoi(av[i]));
		if (!a)
			exit(error());
		i++;
	}
	while (a->prev != NULL)
		a = a->prev;
	board->a = a;
	board->b = NULL;
	return (board);
}

int	check_duplicates(t_board *board)
{
	t_stack	*stack;
	t_stack	*compares;

	stack = board->a;
	while (stack->next != NULL)
	{
		compares = stack->next;
		while (compares->next != NULL)
		{
			if (stack->nb == compares->nb)
				return (0);
			compares = compares->next;
		}
		if (stack->nb == compares->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_board	*create_board(t_board *board, char **av, int start)
{
	board = (t_board *)malloc(sizeof(t_board));
	if (!board)
		return (NULL);
	if (!check_av(av, start))
		return (NULL);
	board = push_swap(board, av, start);
	if (!check_duplicates(board))
	{
		free_board(board);
		return (NULL);
	}
	return (board);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		ft_printf("nb = %d || rank = %d\n", stack->nb, stack->rank);
		stack = stack->next;
	}
	ft_printf("nb = %d || rank = %d\n", stack->nb, stack->rank);
}

void	get_rank(t_stack *stack)
{
	t_stack	*start;
	t_stack *b;
	int		rank;
	
	start = stack;
	while(stack)
	{
		rank = 1;
		b = start;
		while (b)
		{
			if (stack->nb > b->nb)
				rank += 1;
			b = b->next;
		}
		stack->rank = rank;
		stack = stack->next;
	}
}