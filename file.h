struct	s_file
{
	char	*content;
	unsigned int size;
};

# define BUFFER_SIZE 128

struct s_file *load_file(char *file);

unsigned int line_count(struct s_file file);

void free_file(struct s_file *file);

