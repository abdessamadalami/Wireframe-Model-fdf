/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:00:18 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 06:58:34 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;
	t_list	*node;

	list = *lst;
	if (list != NULL)
	{
		node = ft_lstlast(list);
		node -> next = new;
	}
	else
		(*lst) = new;
}
/*
void printList(t_list *a) {
   
   t_list *ptr = a;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr)
   {
      printf("( %d ) ",*(int *)ptr -> content);
      ptr = ptr->next;
   }
   printf(" ]");
}
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;

}
int main()
{
	t_list *a;
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
        a = ft_lstnew(&tab);
    int i = 0;
    while (i<4)
	{
        node = ft_lstnew(f(tab1[i]));
      //  printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&a,node);
        i++;
    }
	printList(a);
   // printf("\nthe content of node is = %d \n", *(int *)a -> content);
   
}
*/
