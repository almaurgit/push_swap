/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:07:35 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 17:13:32 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef	struct s_pile		t_pile;

struct		s_pile
{
	int		n;
	t_pile	*next;
};

void		put_inst(t_pile **a, t_pile **b, int nb, ...);

int			get_pile_a(int ac, char **av, t_pile **a, int i);
int			add_pile(t_pile **p, int n);
int			length_stack(t_pile *p);
t_pile		*last_elem(t_pile *p);
void		quicksort(t_pile **list, int reverse);
int			sort_stack(t_pile **a, t_pile **b, t_pile *copy);
void		remove_pile(t_pile **p);

void		delete_piles(t_pile *a, t_pile *b);
void		delete_stack(t_pile *p);
int			valid_stack(t_pile *a, t_pile *b);
int			error(t_pile *a, t_pile *b);
void		print_list(t_pile *p);

void		sort_3(t_pile **a, t_pile **b);
void		sort_under_5(t_pile **a, t_pile **b);

void		exec_instructions(char *s, t_pile **a, t_pile **b);
void		swap(t_pile **b);
void		rotate(t_pile **b);
void		rev_rotate(t_pile **b);
void		push(t_pile **a, t_pile **b);

int			get_posmax(t_pile *p);
int			get_posmin(t_pile *p);
int			max(int a, int b);
int			min(int a, int b);
t_pile		*last_elem(t_pile *p);
int			nb_pieces_stack(int len);
int			get_list_index(t_pile *copy, int index);
int			get_max(t_pile *a);
int			get_min(t_pile *a);
int			nb_elements(t_pile *a, int max, int min);
int			is_int(char *s);
int			is_overflow(char *s);
int			doublon(t_pile *p, int n);
t_pile		*copy_list(t_pile *a);
t_pile		*partial_copy(t_pile *p, int start, int end, int sorted);

#endif
