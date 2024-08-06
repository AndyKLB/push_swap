/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:02:11 by ankammer          #+#    #+#             */
/*   Updated: 2024/06/11 14:32:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	t_stack_node	*last_node;

	last_node = head;
	if (!head)
		return (NULL);
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

t_stack_node	*find_max_node(t_stack_node *head)
{
	t_stack_node	*stack_max;

	stack_max = head;
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->value > stack_max->value)
			stack_max = head;
		head = head->next;
	}
	return (stack_max);
}

t_stack_node	*find_min_node(t_stack_node *head)
{
	t_stack_node	*stack_min;

	stack_min = head;
	while (head)
	{
		if (head->value < stack_min->value)
			stack_min = head;
		head = head->next;
	}
	return (stack_min);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack_a)
{
	int	count;

	if (!stack_a)
		return (0);
	count = 0;
	while (stack_a)
	{
		count++;
		stack_a = stack_a->next;
	}
	return (count);
}
