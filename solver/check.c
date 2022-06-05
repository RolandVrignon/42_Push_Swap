/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:42:24 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/05 12:37:41 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_stack(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next != NULL && stack->nb > stack->next->nb)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
