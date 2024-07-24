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
	int				target_b;
	int				target_a;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

#endif