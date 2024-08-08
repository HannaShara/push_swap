/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:07:41 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/23 14:07:43 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	biggest;

	biggest = stack->index;
	while (stack)
	{
		if (biggest < stack->index)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
}

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (check_sorted(*stack))
		return ;
	biggest = find_biggest(*stack);
	if ((*stack)->index == biggest)
		ra(stack);
	else if ((*stack)->next->index == biggest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size--;
	}
	sort_three(stack_a);
	if (!check_sorted_reverse(*stack_b))
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
