/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:28:24 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/11 14:10:24 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push_case(t_list *a, t_list *b)
{
	t_list	*pb;
	int		countb;
	int		lb;

	pb = b;
	countb = 0;
	lb = ft_lstlast(b);
	while (pb->next)
	{
		if ((a->num > pb->num && pb->num > lb)
			|| (lb > a->num && a->num > pb->num)
			|| (pb->num > lb && lb > a->num))
			break ;
		pb = pb->next;
		countb++;
	}
	return (countb);
}

void	set_current(t_list *a, t_list *b, int current[7], int counta)
{
	t_list	*pa;
	int		i;
	int		countb;

	pa = a;
	i = counta;
	while (i-- > 0)
		pa = pa->next;
	countb = 0;
	countb = push_case(pa, b);
	current[0] = counta;
	current[1] = countb;
	if (counta)
		current[2] = ft_lstsize(a) - counta;
	else
		current[2] = 0;
	if (countb)
		current[3] = ft_lstsize(b) - countb;
	else
		current[3] = 0;
	ft_current_final(current);
	current[6] = 0;
	i = 0;
	while (i < 6)
		current[6] += current[i++];
}

static void	cheap_init(int cheap[7], t_list *a, t_list *b, int lb)
{
	t_list	*pb;
	int		countb;

	countb = 0;
	pb = b;
	while (a && pb && pb->next)
	{
		if ((a->num > pb->num && pb->num > lb)
			|| (lb > a->num && a->num > pb->num)
			|| (pb->num > lb && lb > a->num))
			break ;
		pb = pb->next;
		countb++;
	}
	cheap[0] = 0;
	cheap[2] = 0;
	cheap[4] = 0;
	cheap[5] = 0;
	if (countb <= ft_lstsize(b) / 2)
		cheap[1] = countb;
	else
		cheap[3] = ft_lstsize(b) - countb;
	cheap[6] = cheap[1] + cheap [3];
}

void	arr_init(int arr[7])
{
	int	i;

	i = 0;
	while (i < 7)
		arr[i++] = 0;
}

void	ft_cheapest(int cheap[7], t_list *a, t_list *b, int lb)
{
	int		current[7];
	int		counta;
	int		i;
	t_list	*pa;

	arr_init(cheap);
	arr_init(current);
	cheap_init(cheap, a, b, lb);
	pa = a;
	counta = 0;
	while (pa)
	{
		set_current(a, b, current, counta);
		i = 0;
		if (current[6] < cheap[6])
		{
			while (i < 7)
			{
				cheap[i] = current[i];
				i++;
			}
		}
		pa = pa->next;
		counta++;
	}
}
