#include "str_linked_list.h"
#include "ftlib.h"
#include <stdlib.h>

struct s_str_dlinked_list 	*str_dllist_create_node(char *str)
{
	struct s_str_dlinked_list *list = malloc(sizeof(struct s_str_dlinked_list));
	list->previous = NULL;
	list->str = ft_strdup(str);
	list->next = NULL;
	return list;
}

void	str_dllist_add_last(struct s_str_dlinked_list *list, char *str)
{
	struct s_str_dlinked_list *last_node = list;
	while(last_node->next)
		last_node = last_node->next;
	last_node->next = str_dllist_create_node(str);
	last_node->next->previous = last_node;
}

void free_str_dlinked_node(struct s_str_dlinked_list *node)
{
	free(node->str);
	free(node);
}

void free_str_dlinked_list(struct s_str_dlinked_list *list) {
	struct s_str_dlinked_list *first_node = list;
	while (first_node->previous)
		first_node = first_node->previous;
	struct s_str_dlinked_list *next_node;
	while (first_node)
	{
		next_node = first_node->next;
		free_str_dlinked_node(first_node);
		first_node = next_node;
	}
}

/*
#include <stdio.h>
int main()
{
	struct s_str_dlinked_list *first = str_dllist_create_node("coucou");
	str_dllist_add_last(first, "salut");
	str_dllist_add_last(first, "holla");

	struct s_str_dlinked_list *it = first;
	while(it)
	{
		printf("%s\n", it->str);
		it = it->next;
	}
	free_str_dlinked_list(first);
}
*/
