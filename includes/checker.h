/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:02:53 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 18:08:10 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"

# define VISU 1
# define NBINST 2

typedef struct s_pile	t_pile;

struct		s_pile
{
	int		n;
	t_pile	*next;
};

void		delete_piles(t_pile *a, t_pile *b);
void		delete_stack(t_pile *p);
int			error(t_pile *a, t_pile *b);
int			valid_stack(t_pile *a, t_pile *b);
void		print_list(t_pile *p);

int			get_pile_a(int ac, char **av, t_pile **a, int i);
int			add_pile(t_pile **p, int n);
void		remove_pile(t_pile **p);
int			read_instructions(char *inst, t_pile **a, t_pile **b, char flag);
int			length_stack(t_pile *p);
void		swap(t_pile **p);
void		rotate(t_pile **p);
void		rev_rotate(t_pile **p);
void		push(t_pile **a, t_pile **b);
void		quicksort(t_pile **list, int reverse);

#endif
