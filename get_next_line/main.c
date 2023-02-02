#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int	fd = open("/mnt/nfs/homes/rtissera/workspacev2/get_next_line/test.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
