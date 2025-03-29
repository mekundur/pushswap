/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:49:49 by mekundur          #+#    #+#             */
/*   Updated: 2024/04/23 19:25:06 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_r(t_list *lst, int flag)
{
	int	tmp;

	if (ft_lstsize(lst) > 1)
	{
		tmp = lst->num;
		while (lst)
		{
			if (!lst->next)
			{
				lst->num = tmp;
				break ;
			}
			lst->num = lst->next->num;
			lst = lst->next;
		}
	}
	if (flag == 'a')
		write(1, "ra\n", 3);
	else if (flag == 'b')
		write(1, "rb\n", 3);
}

void	ft_rr(t_list *a, t_list *b)
{
	if (a && b)
	{
		ft_r(a, 0);
		ft_r(b, 0);
		write(1, "rr\n", 3);
	}
}

void	ft_revr(t_list *lst, int flag)
{
	int		tmp1;
	int		tmp2;
	t_list	*ptr;

	if (ft_lstsize(lst) > 1)
	{
		ptr = lst;
		tmp1 = ptr->num;
		while ((ft_lstsize(lst) > 1) && ptr->next)
		{
			tmp2 = ptr->next->num;
			ptr->next->num = tmp1;
			tmp1 = tmp2;
			ptr = ptr->next;
		}
		lst->num = tmp2;
		if (flag == 'a')
			write(1, "rra\n", 4);
		else if (flag == 'b')
			write(1, "rrb\n", 4);
	}
}

void	ft_revrr(t_list *a, t_list *b)
{
	if (a && b)
	{
		ft_revr(a, 0);
		ft_revr(b, 0);
		write(1, "rrr\n", 4);
	}
}
