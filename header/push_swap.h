/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:43:19 by ankammer          #+#    #+#             */
/*   Updated: 2024/07/08 16:18:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;

}						t_stack_node;
// Handle input
char					**ft_split(char const *s, char c);

// Handle error & free
int						syntax_error(char *input_av);
int						error_repetition(t_stack_node *stack_a, int nb);
void					free_split_av(char **input_av);
void					free_error(t_stack_node **stack_a, char **input_av,
							bool av_is_split);
void					free_stack(t_stack_node **stack_a);

// Stack utils
void					stack_init(t_stack_node **stack_a, char **input_av,
							bool av_is_split);
void					add_node(t_stack_node **stack_a, int nb);
int						stack_len(t_stack_node *stack_a);
t_stack_node			*find_last_node(t_stack_node *head);
t_stack_node			*find_max_node(t_stack_node *head);
t_stack_node			*find_min_node(t_stack_node *head);
t_stack_node			*return_cheapest(t_stack_node *stack);

// List utils
bool					stack_sorted(t_stack_node *a);
void					sort_three(t_stack_node **stack_a);
void					sort_stacks(t_stack_node **stack_a,
							t_stack_node **stack_b);

void					set_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void					set_index(t_stack_node *stack_head);
void					end_rotation(t_stack_node **stack,
							t_stack_node *head_node, char stack_name);
void					sort_five(t_stack_node **stack_a,
							t_stack_node **stack_b);

// Push_swap commands
void					swap(t_stack_node **stack_head);
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);

void					push(t_stack_node **src, t_stack_node **dest);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);

void					rotate(t_stack_node **stack_head);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);

void					rev_rotate(t_stack_node **stack_head);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);
#endif