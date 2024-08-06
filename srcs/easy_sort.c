/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:10:35 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/08 16:12:05 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	stack_sorted(t_stack_node *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*stack_max;

	if (!*stack_a || !*stack_a)
		return ;
	stack_max = find_max_node(*stack_a);
	if (*stack_a == stack_max)
		ra(stack_a);
	else if ((*stack_a)->next == stack_max)
		rra(stack_a);
	if (!stack_sorted(*stack_a))
		sa(stack_a);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_len(*stack_a) != 3)
	{
		set_nodes(*stack_a, *stack_b);
		end_rotation(stack_a, find_min_node(*stack_a), 'a');
		pb(stack_a, stack_b);
	}
}
