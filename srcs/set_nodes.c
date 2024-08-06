/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:09:31 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/08 16:12:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	set_index(t_stack_node *stack_head)
{
	int	i;
	int	median;

	if (!stack_head)
		return ;
	i = 0;
	median = stack_len(stack_head) / 2;
	while (stack_head)
	{
		stack_head->index = i;
		if (i <= median)
			stack_head->above_median = true;
		else
			stack_head->above_median = false;
		i++;
		stack_head = stack_head->next;
	}
}

void	set_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
{
	long			best_match;
	t_stack_node	*target_node;
	t_stack_node	*current_a;

	while (stack_b)
	{
		current_a = stack_a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (stack_b->value < current_a->value
				&& current_a->value < best_match)
			{
				target_node = current_a;
				best_match = current_a->value;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_min_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_push_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		if (!(stack_b->above_median))
			stack_b->push_cost = len_b - stack_b->index;
		else
			stack_b->push_cost = stack_b->index;
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - stack_b->target_node->index;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack_node *stack_b)
{
	t_stack_node	*cheapest;
	long			cheapest_value;

	cheapest_value = LONG_MAX;
	if (!stack_b)
		return ;
	while (stack_b)
	{
		if (stack_b->push_cost < cheapest_value)
		{
			cheapest_value = stack_b->push_cost;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	cheapest->cheapest = true;
}

void	set_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_node(stack_a, stack_b);
	set_push_cost(stack_a, stack_b);
	set_cheapest(stack_b);
}
