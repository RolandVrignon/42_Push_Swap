/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:31 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 17:34:26 by rvrignon         ###   ########.fr       */
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

t_stack	*create_list(t_content *content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	if (!content)
	{
		new->content = (t_content *)malloc(sizeof(t_content));
		if (!new->content)
			exit(0);
	}
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*list_add_back(t_stack *prev_stack, t_content *content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	prev_stack->next = new;
	new->prev = prev_stack;
	new->next = NULL;
	new->content = content;
	return (new);
}

t_stack	*list_add_front(t_stack *first_stack, t_content *content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	first_stack->prev = new;
	new->next = first_stack;
	new->prev = NULL;
	new->content = content;
	return (new);
}
