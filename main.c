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
        quicksort(stack_a, stack_b);
}

int get_pivot(t_stack *stack, int i)
{
    while (stack->next != NULL || i != 0)
    {
        stack = stack->next;
        i--;
    }
    return (stack->index);
}

/*
    Fais la trie dans l'ordre decroissant pour pouvoir apres utiliser pa.
*/

void   quicksort_b(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;

    size = stack_size(*stack_b);
    if (stack_size(*stack_b) <= 1 || check_sorted_reverse(*stack_b))
        return;
    pivot = get_pivot(*stack_b, size / 2);
    while (!check_sorted_reverse(*stack_b) && *stack_b)
    {
        if (size == 2)
            sb(stack_b);
        else if (size == 3)
            sort_three_reverse(stack_b);
        else
            {
                if ((*stack_b)->nbr >= pivot)
                    pa(stack_a, stack_b);
                else
                    rb(stack_b);
            }
    }
    if ((*stack_b)->index < (*stack_b)->next->index)
        sb(stack_b);
    if (check_sorted(*stack_b))
    {
        while (!check_sorted_reverse(*stack_b))
            rrb(stack_b);
    }
    quicksort_b(stack_a, stack_b);
}

/*
    Fait la premiere partition, remplit le stack b des nombres inferieures au pivot.
*/

void    quicksort_a(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;

    size = stack_size(*stack_a);
    if (stack_size(*stack_a) <= 1 || check_sorted(*stack_a))
        return;
    pivot = get_pivot(*stack_a, size / 2);
    while (!check_sorted(*stack_a) && *stack_a)
    {        
        if (size == 2)
            sa(stack_a);
        else if (size == 3)
            sort_three(stack_a);
        else
        {
            if ((*stack_a)->nbr <= pivot)
            pb(stack_a, stack_b);
            else
            ra(stack_a);
        }
    }
    if ((*stack_a)->index > (*stack_a)->next->index)
        sa(stack_a);
    if (check_sorted_reverse(*stack_a))
    {
        while (!check_sorted(*stack_a))
            rra(stack_a);
    }
    quicksort_a(stack_a, stack_b);
}

void    quicksort(t_stack **stack_a, t_stack **stack_b)
{
    quicksort_a(stack_a, stack_b);
    quicksort_b(stack_a, stack_b);
    while (!stack_is_empty(*stack_b))
        pa(stack_a, stack_b);
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;
    int     flag;

    flag = 1;
    if (argc < 2)
        return (0);
    if (argc > 2 && !check_input(argv))
        return (write(2, "Error\n", 6));
    if (argc == 2 && check_argv(argv[1]))
    {
        argv = ft_split(argv[1],' ');
        argc = 0;
        while (argv[argc] != NULL)
            argc++;
        flag = 0;
    }
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%d\n", argc);
    stack_a = fill_stack(argc, argv, flag);
    stack_b = NULL;
    size = stack_size(stack_a);
    stack_index(stack_a, size + 1);
    push_swap(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
