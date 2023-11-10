/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:10:29 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/12 06:57:10 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	ptr = malloc((len + 1) * sizeof (char));
	if (ptr == NULL)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
