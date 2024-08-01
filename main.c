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

void    sort_five(t_stack **stack_a, t_stack **stack_b, int size)
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

void    push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size == 2 && !check_sorted(*stack_a))
        sa(stack_a);
    else if (size == 3 && !check_sorted(*stack_a))
        sort_three(stack_a);
    else if (size == 5 && !check_sorted(*stack_a))
        sort_five(stack_a, stack_b, 5);
    else if (size > 3 && !check_sorted(*stack_a))
    {
        partition(stack_a, stack_b, size);
        while (*stack_b != NULL)
            research_next(stack_a, stack_b);
    }
}

void    position_update(t_stack **stack)
{
    t_stack *temp;
    int i;

    i = 0;
    temp = *stack;
    while (temp)
    {
        temp->pos = i;
        temp = temp->next;
        i++;
    }
}

void    research_next(t_stack **stack_a, t_stack **stack_b)
{
    int key;
    int size_b;
    int pos_key;
    t_stack *temp;

    temp = *stack_b;
    position_update(stack_b);
    key = ((*stack_a)->index) - 1;
    size_b = stack_size(*stack_b);
    while (temp->index != key)
        temp = temp->next;
    pos_key = temp->pos;
    if (pos_key < size_b / 2)
    {
        while ((*stack_b)->pos != pos_key)
            rb(stack_b);
    }
    else if (pos_key >= size_b / 2)
    {
        while ((*stack_b)->pos != pos_key)
            rrb(stack_b);
    }
    pa(stack_a, stack_b);
}

void    partition(t_stack **stack_a, t_stack **stack_b, int size)
{
    while (stack_size(*stack_a) != 3)
    {
        if ((*stack_a)->index <= size - 3)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
    sort_three(stack_a);
}

/*
int get_pivot(t_stack *stack, int i)
{
    while (stack->index != i)
    {
        stack = stack->next;
        i--;
    }
    return (stack->index);
}


    Fais la trie dans l'ordre decroissant pour pouvoir apres utiliser pa.


void   quicksort_b(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;
 
    size = stack_size(*stack_b);
    if (check_sorted_reverse(*stack_b) || size <= 1)
        return;
    pivot = get_pivot(*stack_b, size / 2);
    if (stack_b && !check_sorted_reverse(*stack_b))
    {
        if (size == 2)
            sb(stack_b);
        else if (size == 3)
            sort_three_reverse(stack_b);
        else
            {
                if ((*stack_b)->index >= pivot)
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


    Fait la premiere partition, remplit le stack b des nombres inferieures au pivot.


void    quicksort_a(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;
    int count = 0;

    size = stack_size(*stack_a);
    if (check_sorted(*stack_a) || size <= 1 )
        return;
    pivot = get_pivot(*stack_a, size / 2);
    while (size)
    {        
        if (size == 2)
            sa(stack_a);
        else if (size == 3)
            sort_three(stack_a);
        else
        {
            if ((*stack_a)->index <= pivot)
            {
                pb(stack_a, stack_b);
                count++;
            }
            else
            ra(stack_a);
        size--;
    }
    if ((*stack_a)->index > (*stack_a)->next->index)
       sa(stack_a);
    if (check_sorted_reverse(*stack_a))
    {
        while (!check_sorted(*stack_a))
            rra(stack_a);
    }
}

void    quicksort(t_stack **stack_a, t_stack **stack_b)
{
    while (!check_sorted(*stack_a))
    {
    quicksort_a(stack_a, stack_b);
    quicksort_b(stack_a, stack_b);
    while (*stack_b != NULL)
        pa(stack_a, stack_b);
    }
}*/

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

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
        if (!check_input(argv))
            return (write(2, "Error\n", 6));
    }
    stack_a = fill_stack(argc, argv);
    stack_b = NULL;
    size = stack_size(stack_a);
    stack_index(stack_a, size + 1);
    push_swap(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
