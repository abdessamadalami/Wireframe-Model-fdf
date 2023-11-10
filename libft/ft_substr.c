/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:07:12 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 15:12:53 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>
#include<string.h>

static int	min_mal(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	unsigned int	len_sub_str;
	char			*ptr;

	index = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		ptr[0] = 0;
		return (ptr);
	}
	len_sub_str = min_mal(ft_strlen(s) - start, len);
	ptr = malloc(len_sub_str + 1);
	if (ptr == NULL)
		return (0);
	while (index < len_sub_str && s[index] != '\0')
	{
		ptr[index] = s[index + start];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
/*
int main()
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr("tripouille", 0, 42);
	if (strcmp(ret, "tripouille"))
	{
		
		printf(" TEST_SUCCESS ");
	}
    printf("u %d str n %d",*ret,strcmp(ret, "tripouille"));
     
}
"khaliddddd"  2  4
*/
