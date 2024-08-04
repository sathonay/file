#include "file.h"
#include "ftlib.h"
#include "str_linked_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

struct s_file *load_file(char *file_path)
{
	struct s_file *file = malloc(sizeof(struct s_file));
	struct s_str_dlinked_list *file_part;
	unsigned int file_s = 0;
	unsigned int buffer_i = 0;
	char *buffer = malloc(BUFFER_SIZE);

	int file_desc = open(file_path, O_RDONLY);
	
	int read_l = read(file_desc, buffer, BUFFER_SIZE - 1);
	buffer[read_l - 1] = '\0';
	
	file_part = str_dllist_create_node(buffer);
	file_s += read_l;
	while(read_l == BUFFER_SIZE - 1)
	{
		read_l = read(file_desc, buffer, BUFFER_SIZE - 1);
		buffer[read_l] = '\0';
		str_dllist_add_last(file_part, buffer);
		file_s += read_l;	
	}

	close(file_desc);
	char *content = malloc(file_s);
	content[--file_s] = '\0';
	file->size = file_s;

	struct s_str_dlinked_list *last_node = file_part;
	while (last_node->next)
		last_node = last_node->next;
	while (last_node)
	{
		
		buffer_i = ft_strlen(last_node->str);
		while (buffer_i > 0)
		{
			buffer_i--;
			file_s--;
			content[file_s] = last_node->str[buffer_i];
		}
		last_node = last_node->previous;
	}
	file->content = content;
	free_str_dlinked_list(file_part);
	free(buffer);
	return file;
}

unsigned int line_count(struct s_file file)
{
	return 0;
}

void free_file(struct s_file *file)
{
	free(file->content);
	free(file);
}

#include <stdio.h>
int main()
{
	struct s_file *file = load_file("test.txt");
	printf("%s", file->content);
	free_file(file);
}
