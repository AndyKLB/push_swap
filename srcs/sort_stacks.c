/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:02 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/08 16:16:45 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	end_rotation(t_stack_node **stack, t_stack_node *head_node,
		char stack_name)
{
	while (*stack != head_node)
	{
		if (stack_name == 'a')
		{
			if (head_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (head_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	rotate_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (*stack_a != cheapest->target_node && *stack_b != cheapest)
			rr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
	{
		while (*stack_a != cheapest->target_node && *stack_b != cheapest)
			rrr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	end_rotation(stack_a, cheapest->target_node, 'a');
	end_rotation(stack_b, cheapest, 'b');
	pa(stack_a, stack_b);
}

void	final_rotation(t_stack_node **stack_a, t_stack_node *smallest)
{
	if (*stack_a == smallest)
		return ;
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}

void	sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				len;
	t_stack_node	*smallest;

	len = stack_len(*stack_a);
	if (len == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (len-- > 3)
			pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		rotate_nodes(stack_a, stack_b);
	}
	set_index(*stack_a);
	smallest = find_min_node(*stack_a);
	final_rotation(stack_a, smallest);
}
