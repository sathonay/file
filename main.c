#include "file.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		struct s_file *file = load_file(av[1]);
		printf("%s", file->content);
		free_file(file);	
	}
}
