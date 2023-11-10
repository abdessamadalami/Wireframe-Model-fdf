/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:37:32 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/12 08:58:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		index;

	index = ft_strlen((char *)str);
	while (index >= 0)
	{
		if (str[index] == (char)c)
			return ((char *)str + index);
		index--;
	}
	return (NULL);
}

/*
int main()
{
       // printf (" from ft %s from ori  \n", ptr);
    char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *d1 = strrchr("abdessamad", -125);
    int c = -125;
    int d = (unsigned char)c;
    printf("%c",d);
	//char *d2 = ft_strrchr("abdessamad", 'é');
    //printf("d1 = %s  d2 = %s",d1,d2);
	
    if (d1 == d2)
		printf("TEST_SUCCESS");
	  	return 0;
     
}
*/
