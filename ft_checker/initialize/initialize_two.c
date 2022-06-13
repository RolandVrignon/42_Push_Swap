/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:15:24 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 15:50:12 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_board	*push_swap(t_board *board, char **av, int start)
{
	t_stack		*a;
	t_content	*content;
	int			i;

	content = create_content(ft_atoi(av[start]));
	if (!content)
		return (NULL);
	a = create_list(content);
	i = start + 1;
	while (av[i] != NULL)
	{
		content = create_content(ft_atoi(av[i]));
		if (!content)
			return (NULL);
		a = list_add_back(a, content);
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
			if (stack->content->nb == compares->content->nb)
				return (0);
			compares = compares->next;
		}
		if (stack->content->nb == compares->content->nb)
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
	if (!board)
		return (NULL);
	if (!check_duplicates(board))
	{
		free_board(board);
		return (NULL);
	}
	return (board);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("\n\tpos\t|\tnb\t|\trank\n");
	while (++i < 70)
		ft_putchar_fd('-', 1);
	i = 1;
	while (stack)
	{
		ft_printf("\n\t%d :\t|\t%d\t|\t%d\t\n",
			i, stack->content->nb, stack->content->rank);
		i++;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
	i = 0;
	while (++i < 70)
		ft_putchar_fd('-', 1);
	ft_putchar_fd('\n', 1);
}

void	get_rank(t_stack *stack)
{
	t_stack	*start;
	t_stack	*b;
	int		rank;

	start = stack;
	while (stack)
	{
		rank = 0;
		b = start;
		while (b)
		{
			if (stack->content->nb > b->content->nb)
				rank += 1;
			if (b->next != NULL)
				b = b->next;
			else
				break ;
		}
		stack->content->rank = rank;
		if (stack->next != NULL)
			stack = stack->next;
		else
			break ;
	}
}
