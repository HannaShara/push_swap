/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:08:43 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:45 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Return 0 si ce n'est pas trie.
*/

int check_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->nbr > stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/*
    Return 0 si ce n'est pas trie dans l'ordre decroissant.
*/
int check_sorted_reverse(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->nbr < stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}
void    push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size == 2 && !check_sorted(*stack_a))
        sa(stack_a);
    else if (size == 3 && !check_sorted(*stack_a))
        sort_three(stack_a);
    else if (size > 3 && !check_sorted(*stack_a))
        quicksort_partition(stack_a, stack_b);
}

int    stack_position(t_stack **stack)
{
    int i;

    i = 1;
    while ((*stack)->next != NULL)
    {
        (*stack)->pos = i;
        i++;
        stack = (*stack)->next;
    }
    return (i);
}

int get_pivot(t_stack *stack, int i)
{
    while (stack->next != NULL || i != 0)
    {
        stack = stack->next;
        i--;
    }
    return (stack->nbr);
}

/*
    Fais la trie dans l'ordre decroissant pour pouvoir apres utiliser pa.
*/

int    quicksort_b(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int i;

    i = stack_position(stack_b);
    stack_index(stack_b, i + 1);
    pivot = get_pivot(*stack_b, i / 2);
    while (!check_sorted_reverse(*stack_b) && *stack_b)
    {
        if (i == 2)
            sb(stack_b);
        else if (i == 3)
            sort_three_reverse(stack_b);
        else if (i > 3)
            {
                if ((*stack_b)->nbr >= pivot)
                {
                    (*stack_b)->target_b = 1;
                    pa(stack_a, stack_b);
                }
                else
                    rb(stack_b);
            }
        quicksort_b(stack_a, stack_b);
    }
    return ((*stack_b)->index);
}

/*
    Fait la premiere partition, remplit le stack b des nombres inferieures au pivot.
*/

void    quicksort_partition(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int i;
    int index_of_top;
    int temp;

    i = 0;
    if (stack_size(*stack_a) <= 1)
        return;
    pivot = get_pivot(*stack_a, (stack_size(*stack_a) / 2));
    i = pivot;
    while (i)
    {
        if ((*stack_a)->nbr <= pivot)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i--;
    }
    index_of_top = quicksort_b(stack_a, stack_b);
    while ((*stack_a)->target_b == 1) // a corriger car ne bouge pas et maarche pour les deux premiers seulement
    {
        if ((*stack_a)->index == index_of_top + 1)
            pb(stack_a, stack_b);
        else if ((*stack_a)->next->index == index_of_top + 1)
        {
            temp = (*stack_a)->next->nbr;
            (*stack_a)->next->nbr = (*stack_a)->nbr;
            (*stack_a)->nbr = temp;
        }
        index_of_top++;
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

    if (argc < 2 || (argc == 2 && !check_argv(argv[1])))
        return (1);
    if (!check_input(argc, argv))
        ft_error(NULL, NULL);
    if (argc == 2 && check_argv(argv[1]))
        argv = ft_split(argv[1],' ');
    stack_a = fill_stack(argc, argv);
    stack_b = NULL;
    size = stack_size(stack_a);
    push_swap(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
