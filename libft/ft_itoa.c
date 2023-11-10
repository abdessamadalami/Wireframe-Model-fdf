/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:18:40 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 14:05:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

static int	chec_nbr(long nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

static int	tab_itoa(int *tab, int n)
{
	int		index;
	long	nbr;

	nbr = n;
	index = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr == 0)
	{
		tab[0] = 0;
		index++;
	}
	while (nbr >= 1)
	{
		tab[index++] = nbr % 10;
		nbr = nbr / 10;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	int		index;
	int		tab[13];
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = chec_nbr(n);
	index = tab_itoa(tab, n);
	ptr = malloc(index + 1);
	if (ptr == NULL)
		return (0);
	if (j == 1)
		ptr[0] = '-';
	while (i < index)
	{
		ptr[j] = tab[index - i - 1] + '0';
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
int main()
{
  char *ptr = ft_itoa(-0);
   //char *ptr = ft_itoa('0');
   printf("  _%s_",ptr);
}
*/
