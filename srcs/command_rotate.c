/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:46:52 by ankammer          #+#    #+#             */
/*   Updated: 2024/06/11 13:52:49 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate(t_stack_node **stack_head)
{
	t_stack_node	*last_node;

	if (!*stack_head || !stack_head || stack_len(*stack_head) == 1)
		return ;
	last_node = find_last_node(*stack_head);
	last_node->next = *stack_head;
	*stack_head = (*stack_head)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	(*stack_head)->prev = NULL;
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
