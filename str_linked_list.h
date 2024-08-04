struct	s_str_dlinked_list
{
	struct s_str_dlinked_list *previous;
	char *str;
	struct s_str_dlinked_list *next;
};

struct s_str_dlinked_list 	*str_dllist_create_node(char *str);

struct s_str_dlinked_list 	*str_dllist_create_node(char *str);

struct s_str_dlinked_list 	*str_dllist_add_last(struct s_str_dlinked_list *list, char *str);

void free_str_dlinked_list(struct s_str_dlinked_list *list);

