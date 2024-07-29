/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:15 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 15:45:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Vous devez écrire un programme nommé push_swap qui prend en paramètre la
pile a sous la forme d’une liste d’entiers. Le premier paramètre est au 
sommet de la pile (attention donc à l’ordre).
*/

t_stack *fill_stack(int argc, char *argv[], int i)
{
    int     nbr;
    t_stack *stack_a;

    printf("%d\n", i);
    if (i == 0)
        argc += 1;
    printf("%d\n", argc);
    nbr = ft_atoi(argv[i]);
    stack_a = new_stack((int)nbr);
    if (nbr > INT_MAX || nbr < INT_MIN)
        ft_error(&stack_a, NULL);
    i++;
    while (i < argc)
    {
        nbr = ft_atoi(argv[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            ft_error(&stack_a, NULL);
        else
            add_bottom(&stack_a, new_stack((int)nbr));
        i++;
    }
    return(stack_a);
}

/*
(1) Un double pointeur est nécessaire car la fonction doit pouvoir modifier 
le pointeur vers le début de la pile.
(2)Vérification de stack : !stack vérifie si le pointeur stack lui-même est NULL. 
Dans ce cas, il n'y a rien à libérer car il n'y a pas de pile à gérer. 
Vérification de *stack : !(*stack) vérifie si le pointeur pointé par stack
(c'est-à-dire, le début de la pile) est NULL. 
Cela signifie que la pile est vide, c'est-à-dire, elle ne contient aucun élément. 
*/

void    free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free((*stack));
        *stack = tmp;
    }
    *stack = NULL;
}

/*
Attribue des indices décroissants aux éléments de la pile 
en fonction de l'ordre décroissant de leurs valeurs. *		
nbr:		-3	 0	 9	 2
index:		[1]	[2]	[4]	[3]

*/

void    stack_index(t_stack *stack, int size)
{
    t_stack *ptr;
    t_stack *top;
    int     nbr;

    while (--size > 0)
    {
        ptr = stack;
        nbr = INT_MIN;
        top = NULL;
        while (ptr)
        {
            if (ptr->nbr == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            if (ptr->nbr > nbr && ptr->index == 0)
            {
                nbr = ptr->nbr;
                top = ptr;
                ptr = stack;
            }
            else
                ptr = ptr->next;
        }
        if (top != NULL)
            top->index = size;
    }
}