/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:08:31 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 12:26:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

/* how many col ihave my arra 2d and the start and end to any word*/
static int	nbr_word(char *s, char c, int *ptr_se)
{
	int	i;
	int	index;
	int	counter;

	i = 0;
	index = 0;
	counter = 1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			ptr_se[index++] = i;
			counter++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		ptr_se[index++] = i;
	}
	ptr_se[index] = -1;
	return (counter);
}
/*this func working like ft_strdup funct jsut add start and the end */

static char	*ft_str_end(char *src, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((end - start + 1) * sizeof (char));
	if (ptr == NULL)
		return (0);
	while (start < end)
	{
		ptr[i] = src[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* this fun give the start and end postsion of the string u must cpy */

char	**ft_split(char const *s, char c)
{
	int		index;
	int		len;
	int		m;
	int		*ptr_se;
	char	**array;

	index = 0;
	m = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	ptr_se = malloc(len * sizeof(int));
	array = malloc((nbr_word((char *)s, c, ptr_se)) * sizeof (char **));
	if (array == NULL || ptr_se == NULL)
		return (0);
	while (m < nbr_word((char *)s, c, ptr_se) - 1)
	{
		array[m] = ft_str_end((char *)s, ptr_se[index], ptr_se[index + 1]);
		m++;
		index += 2;
	}
	array[m] = NULL;
	free(ptr_se);
	return (array);
}
/*
int main()
{

	char *x = "xakjdnjkdxkdnkjdfvx";
	char c = 'x';
	char **s = ft_split(x, c);
	for (int i = 0; s[i] != '\0'; i++)
		for(int j = 0; s[i][j] != '\0'; j++)
			printf("%c", s[i][j]);
}
*/
