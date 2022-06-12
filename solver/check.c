/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:42:24 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 17:19:05 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_stack(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next != NULL && stack->content->nb > stack->next->content->nb)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
