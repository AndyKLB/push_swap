/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:38 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/08 12:50:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_split_av(char **input_av)
{
	int	i;

	i = 0;
	if (!input_av || !input_av[0])
		return ;
	while (input_av[i])
	{
		free(input_av[i]);
		i++;
	}
	free(input_av);
}

void	free_stack(t_stack_node **stack_a)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack_a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	current = NULL;
}

void	free_error(t_stack_node **stack_a, char **input_av, bool av_is_split)
{
	free_stack(stack_a);
	if (av_is_split)
		free_split_av(input_av);
	write(2, "Error\n", 6);
	exit(1);
}

int	syntax_error(char *input_av)
{
	if (!input_av || !input_av[0])
		return (1);
	if (!(*input_av == '+' || *input_av == '-') && !(*input_av >= '0'
			&& *input_av <= '9'))
		return (1);
	if ((*input_av == '+' || *input_av == '-') && !(input_av[1] >= '0'
			&& input_av[1] <= '9'))
		return (1);
	while (*++input_av)
	{
		if (!(*input_av >= '0' && *input_av <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *stack_a, int nb)
{
	while (stack_a)
	{
		if (stack_a->value == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
