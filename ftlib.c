#include "ftlib.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int ft_strlen(char *str)
{
	unsigned int len = 0;
	while(*str)
	{
		str++;
		len++;
	}
	return len;
}

char 	*ft_strdup(char *str)
{
	unsigned len = ft_strlen(str);
	char *dest = malloc(len + 1);
	dest[len] = '\0';
	while(len > 0)
	{
		len--;
		dest[len] = str[len];
	}
	return dest;
}
