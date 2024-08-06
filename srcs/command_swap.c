/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:31:33 by ankammer          #+#    #+#             */
/*   Updated: 2024/06/11 13:52:15 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_stack_node **stack_head)
{
	int	len;

	len = stack_len(*stack_head);
	if (!stack_head || !*stack_head || len == 1)
		return ;
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev->prev = *stack_head;
	(*stack_head)->prev->next = (*stack_head)->next;
	if ((*stack_head)->next)
		(*stack_head)->next->prev = (*stack_head)->prev;
	(*stack_head)->next = (*stack_head)->prev;
	(*stack_head)->prev = NULL;
}

void	sa(t_stack_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
