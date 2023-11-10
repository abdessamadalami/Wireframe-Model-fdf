/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:31:48 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 18:53:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	t_list	*l;

	list = NULL;
	l = lst;
	if (!lst || !f)
		return (NULL);
	while (l != NULL)
	{
		node = ft_lstnew(f(l -> content));
		if (!node)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		l = l -> next;
	}
	return (list);
}
/*
int *f_allocation(int a)
{
    int *ptr;
	ptr = (int *)malloc(sizeof(int));
	*ptr = a;
	return ptr;

}

void del(void *ptr)
{
	 free(ptr);
}

void *f( void *ptr)
{
    int var = *(int *)ptr + 10;
	return(f_allocation (var));
}


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

int main()
{
	t_list *list;
	t_list *node;
    t_list *new_list;
	
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
        list  = ft_lstnew(f_allocation(tab));
    int i = 0;
    while (i<4)
	{
        node = ft_lstnew(f_allocation(tab1[i]));
      //  printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&list, node);
        i++;
    }
//    printList(list);
   new_list = ft_lstmap(list, f, del);
   printList (new_list);
}
*/
