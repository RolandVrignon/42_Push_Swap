/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:31 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 15:21:52 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		exit(0);
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
		exit(0);
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

int	check_duplicates(t_board *board)
{
	t_stack *stack;
    t_stack *compares;
	
	stack = board->a;
	while (stack->next != NULL)
	{
        compares = stack->next;
        while(compares->next != NULL)
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

t_board	*create_board(t_board *board, char **av)
{
	board = (t_board *)malloc(sizeof(t_board));
	if (!board)
	    return (NULL);
	if (!check_av(av))
		return (NULL);
	board = push_swap(board, av);
	if (!check_duplicates(board))
    {
        free_board(board);
        return (NULL);
    }
	return (board);	
}

void    print_stack(t_stack *stack)
{
    while (stack->next != NULL)
    {
        ft_printf("%d\n", stack->nb);
        stack = stack->next;
    }
    ft_printf("%d\n", stack->nb);
}