/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:20:19 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 15:20:22 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !check_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3 && !check_sorted(*stack_a))
		sort_three(stack_a);
	else if (size == 5 && !check_sorted(*stack_a))
		sort_five(stack_a, stack_b, 5);
	else if (size > 5 && !check_sorted(*stack_a))
	{
		partition(stack_a, stack_b, size);
		while (*stack_b != NULL)
		{
			if ((*stack_a)->index > (*stack_a)->next->index)
				sa(stack_a);
			research_next(stack_a, stack_b);
		}
	}
}

void	partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	five_of_size;

	five_of_size = size / 5;
	chunk(stack_a, stack_b, five_of_size);
	chunk(stack_a, stack_b, five_of_size * 2);
	chunk(stack_a, stack_b, five_of_size * 3);
	if (five_of_size * 4 <= size - 3)
		chunk(stack_a, stack_b, five_of_size * 4);
	chunk(stack_a, stack_b, size - 3);
	sort_three(stack_a);
}
