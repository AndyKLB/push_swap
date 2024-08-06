/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:12:02 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/15 12:10:45 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	ft_atol(char *input_av)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (input_av[i] == ' ' || (input_av[i] >= 9 && input_av[i] <= 13))
		i++;
	if (input_av[i] == '+' || input_av[i] == '-')
	{
		if (input_av[i] == '-')
			sign = -1;
		i++;
	}
	while (input_av[i] >= '0' && input_av[i] <= '9')
	{
		res = (res * 10) + (input_av[i] - 48);
		if ((res > INT_MAX || res < INT_MIN)
			&& (res != 2147483648 && sign != -1))
			return (2147483648);
		i++;
	}
	return (res * sign);
}

void	add_node(t_stack_node **stack_a, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = nb;
	node->next = NULL;
	if (!*stack_a)
	{
		*stack_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_a);
		last_node->next = node;
		node->prev = last_node;
		node->next = NULL;
	}
}

void	stack_init(t_stack_node **stack_a, char **input_av, bool av_is_split)
{
	int		i;
	long	nb;

	if (av_is_split)
		i = 0;
	else
		i = 1;
	while (input_av[i])
	{
		if (syntax_error(input_av[i]))
			free_error(stack_a, input_av, av_is_split);
		nb = ft_atol(input_av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_error(stack_a, input_av, av_is_split);
		if (error_repetition(*stack_a, (int)nb))
			free_error(stack_a, input_av, av_is_split);
		add_node(stack_a, (int)nb);
		i++;
	}
	if (av_is_split)
		free_split_av(input_av);
}
