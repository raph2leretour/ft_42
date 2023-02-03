#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int	fd = open("/mnt/nfs/homes/rtissera/workspacev2/get_next_line/test.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
