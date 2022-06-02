/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:15 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 14:26:26 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int		error()
{
	ft_printf("Error");
	return(0);
}

int		check_av(char **av)
{
	int i;
	char *str;

	i = 1;
	while (av[i] != NULL)
	{
		str = av[i];
		while (*str)
		{
			if (*str == ' ' || ft_isdigit(*str))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1)))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1)))
				str++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

t_stack	*create_list(char *str)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		exit(error());
	new->nb = ft_atoi(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*list_add(t_stack *prev_stack, char *str)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		exit(error());
	prev_stack->next = new;
	new->prev = prev_stack;
	new->next = NULL;
	new->nb = ft_atoi(str);
	return (new);
}

t_board	*push_swap(t_board *board, char **av)
{
	t_stack *a;
	t_stack *b;
	int		i;

	(void)b;
	a = create_list(av[1]);
	i = 2;
	while(av[i] != NULL)
	{
		a = list_add(a, av[i]);
		if (!a)
			exit(error());
		i++;
	}
	while(a->prev != NULL)
		a = a->prev;
	board->a = a;
	board->b = NULL;
	return (board);
}

void	print_stack(t_board *board)
{
	t_stack *stack;
	
	stack = board->a;
	while (stack->next != NULL)
	{
		ft_printf("%d\n", stack->nb);
		stack = stack->next;
	}
}

t_board	*create_board(t_board *board, char **av)
{
	board = (t_board *)malloc(sizeof(t_board));
	if (!board)
		exit (error());
	if (!check_av(av))
		exit (error());
	board = push_swap(board, av);
	print_stack(board);
	return (board);
	
}

int		main(int ac, char **av)
{
	t_board	*board;

	board = NULL;
	(void)board;
	if (ac < 2)
		return (error());
	board = create_board(board, av);
	return (1);
}