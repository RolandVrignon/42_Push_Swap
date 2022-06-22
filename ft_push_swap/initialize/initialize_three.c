/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:27 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/22 23:25:12 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_content	*create_content(long int nb)
{
	t_content	*content;

	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->nb = nb;
	content->rank = 0;
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
