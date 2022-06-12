/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:31 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 14:56:27 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(void)
{
	ft_printf("Error");
	return (0);
}

int	check_av(char **av, int start)
{
	int		i;
	char	*str;

	i = start;
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

t_stack	*create_list(long int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*list_add_back(t_stack *prev_stack, long int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	prev_stack->next = new;
	new->prev = prev_stack;
	new->next = NULL;
	new->nb = nb;
	return (new);
}

t_stack	*list_add_front(t_stack *first_stack, long int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	first_stack->prev = new;
	new->next = first_stack;
	new->prev = NULL;
	new->nb = nb;
	return (new);
}
