/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:27 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 18:52:16 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_gap(t_stack *stack)
{
	int	i;

	i = 1;
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
	content->nb = nb;
	content->rank = 0;
	content->gap = 0;
	return (content);
}
