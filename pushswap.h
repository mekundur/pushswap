/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:20:33 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/09 16:33:58 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		input_check(char **arr);
int		ft_atoi(const char *nptr);
size_t	ft_white_space(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(const char *s, char c);

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

void	ft_sorting(t_list **a, t_list **b);
int		push_swap(char **arr);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int num);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **a, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsorted(t_list *a);
int		revsort(t_list *b);
int		ft_lstlast(t_list *lst);
int		ft_lstmax(t_list *lst);
void	two_numbers(t_list *a);
void	three_numbers(t_list *a);
void	five_numbers(t_list **a, t_list **b);
void	many_numbers(t_list **a, t_list **b);
void	ft_cheapest(int cheap[7], t_list *a, t_list *b, int lb);
void	ft_cheapinit(int cheap[7], t_list *a, t_list *b, int lb);
void	ft_countr(int arr[7]);
void	ft_current_final(int arr[7]);
void	ft_s(t_list *lst, int flag);
void	ft_ss(t_list *a, t_list *b);
void	ft_r(t_list *lst, int flag);
void	ft_rr(t_list *a, t_list *b);
void	ft_revr(t_list *lst, int flag);
void	ft_revrr(t_list *a, t_list *b);
void	ft_p(t_list **lst1, t_list **lst2, int flag);

#endif
