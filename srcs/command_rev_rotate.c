/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:19:39 by ankammer          #+#    #+#             */
/*   Updated: 2024/06/11 14:13:31 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rev_rotate(t_stack_node **stack_head)
{
	t_stack_node	*last_node;

	if (!*stack_head || !stack_head || stack_len(*stack_head) == 1)
		return ;
	last_node = find_last_node(*stack_head);
	last_node->next = *stack_head;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next->prev = last_node;
	*stack_head = last_node;
}

void	rra(t_stack_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
