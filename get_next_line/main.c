#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
