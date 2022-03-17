/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/17 18:10:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"

void check_list(t_list *list)
{
	int index;
	int line_nbr;
	int *arry;
	int length;
	char **split_array;
	
	
		
	split_array = ft_lstsize(list);
	length = ft_strlen_s(split_array);
	line_nbr = ft_lstsize(list) - 1;
	arry = (int **)malloc(line_nbr * length * 4);
	index = 0;
	while(list)
	{
		arry = ft_split(list-> content, 32);
		while(arry[i])
		{
			
		}
		list = list -> next;
	}
}