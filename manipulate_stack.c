/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:07:38 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 17:07:40 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Ces champs sont initialisés à -1 comme une valeur sentinelle ou par défaut pour
indiquer une absence de valeur significative ou une position indéfinie. 
Dans de nombreux algorithmes de tri ou de manipulation de piles, 
il est courant d'utiliser -1 pour indiquer une valeur par défaut ou une position
non valide avant que ces champs ne soient correctement initialisés ou calculés.
*/

t_stack *new_stack(int nbr)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
    	ft_error(NULL, NULL);
    new->nbr = nbr;
    new->index = -1;
    new->pos = -1;
    new->next = NULL;
    return (new);
}

t_stack *get_bottom(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

t_stack *get_before_bottom(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}

void    add_bottom(t_stack **stack, t_stack *new)
{
    t_stack *end;
    
    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    end = get_bottom(*stack);
    end->next = new;
}

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}
