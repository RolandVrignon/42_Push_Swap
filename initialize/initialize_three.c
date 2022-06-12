/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:27 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 01:00:28 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_gap(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		stack->content->gap = stack->content->rank - i;
		stack = stack->next;
		i++;
	}
	stack->content->gap = stack->content->rank - i;
}

t_content	*create_content(long int nb)
{
	t_content	*content;

	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	if (nb > 2147483647 || nb < -2147483648)
		return (NULL);
	content->nb = nb;
	content->rank = 0;
	content->gap = 0;
	return (content);
}

int	lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
