/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:06:56 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/15 13:06:59 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

t_stack *fill_stack(int argc, char *argv[]);
void    free_stack(t_stack **stack);
void    stack_index(t_stack *stack, int size);

int	arg_is_number(char *argv);
int	arg_is_zero(char *argv);
int	check_duplicata(char **argv);
int	check_input(char **argv);

int find_biggest(t_stack *stack);
void    sort_three(t_stack **stack);
int find_smallest(t_stack *stack);
void    sort_three_reverse(t_stack **stack);

int check_sorted(t_stack *stack);
int check_sorted_reverse(t_stack *stack);
void    push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int get_pivot(t_stack *stack, int i);
void   quicksort_b(t_stack **stack_a, t_stack **stack_b);
void    quicksort_a(t_stack **stack_a, t_stack **stack_b);
void    quicksort(t_stack **stack_a, t_stack **stack_b);

t_stack *new_stack(int nbr);
t_stack *get_bottom(t_stack *stack);
t_stack *get_before_bottom(t_stack *stack);
void    add_bottom(t_stack **stack, t_stack *new);
int stack_size(t_stack *stack);

void	ft_push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void    reverse_rotate(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	ft_swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

int	ft_nbrcmp(const char *s1, const char *s2);
void	ft_error(t_stack **stack_a, t_stack **stack_b);
int	check_argv(char *s1);
int	stack_is_empty(t_stack *stack);

#endif