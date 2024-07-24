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

int find_biggest(t_stack *stack)
{
    int biggest;

    biggest = stack->nbr;
    while(stack)
    {
        if (biggest < stack->nbr)
            biggest = stack->nbr;
        stack = stack->next;
    }
    return (biggest);
}

void    sort_three(t_stack **stack)
{
    int biggest;

    if (check_sorted(*stack))
        return;
    biggest = find_biggest(*stack);
    if ((*stack)->nbr == biggest)
        ra(stack);
    else if ((*stack)->next->nbr == biggest)
        rra(stack);
    if ((*stack)->nbr > (*stack)->next->nbr)
        sa(stack);
}

int find_smallest(t_stack *stack)
{
    int smallest;

    smallest = stack->nbr;
    while(stack)
    {
        if (smallest > stack->nbr)
            smallest = stack->nbr;
        stack = stack->next;
    }
    return (smallest);
}
void    sort_three_reverse(t_stack **stack)
{
    int smallest;

    if (check_sorted_reverse(*stack))
        return;
    smallest = find_smallest(*stack);
    if ((*stack)->nbr == smallest)
        rb(stack);
    else if ((*stack)->next->nbr == smallest)
        rrb(stack);
    if ((*stack)->nbr < (*stack)->next->nbr)
        sb(stack);
}