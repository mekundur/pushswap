/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:33:30 by mekundur          #+#    #+#             */
/*   Updated: 2024/04/22 13:14:46 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

static char	**free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

static size_t	ft_string_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	**ft_put_string(char const *s1, char c, char **arr, size_t wcount)
{
	size_t	i;
	char	*s2;
	char	*str;

	s2 = (char *)s1;
	i = 0;
	while (*s1 && i < wcount)
	{
		while (*s2 == c)
		{
			s1++;
			s2++;
		}
		while (*s2 != c && *s2 != '\0')
			s2++;
		str = (char *)malloc((s2 - s1 + 1) * sizeof(char));
		if (!str)
			return (free_array(arr));
		ft_strlcpy(str, s1, (s2 - s1 + 1));
		arr[i++] = str;
		s1 = s2;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	wcount;

	if (!s)
		return (0);
	wcount = ft_string_count(s, c);
	arr = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!arr)
		return (0);
	ft_put_string(s, c, arr, wcount);
	return (arr);
}
/*
int	main(int argc, char **argv)
{
	char	**arr;
	size_t	i;

	i = 0;
	printf("argc: %d\n", argc);
	arr = ft_split(argv[1], ' ');
	while (arr && arr[i]) 
		printf("%s\n", arr[i++]);
	free_array(arr);
	return (0);
}
*/
