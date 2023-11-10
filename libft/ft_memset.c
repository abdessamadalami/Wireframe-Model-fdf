/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:05:02 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:22 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
/*
int main()
{
//    int tab[]={1,2,3,4};
 int tab[7] = {49, 49, 1, -1, 0, -2, 2};
//n256 in memory is 10000000i0 
 
 char a[]="abcdessamad";  
 ft_memset(a , '_' , 100);

// printf("%s",(memset("abcdef",'_' , 100)));

		// printf(" _%d_ ",tab[0]);
}
*/
