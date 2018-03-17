#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int                main(void)
{
	char        *line;
	int            fd;
	int            ret;
	char        *filename;

	filename = "file2";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		if (close(fd) == 0)
		{
			line = NULL;
				printf("fd = %d\n", fd);
				ret = read(fd, line, BUFF_SIZE);
				printf("ret = %d\n", ret);
			ret = get_next_line(fd, &line);
//				printf("ret = %d\n", ret);
/*			if (ret != -1)
				printf("-> must have returned '-1' when receiving a closed file descriptor\n");
			else
				printf("OK\n");
		}
		else
		{
			printf("An error occured while closing file descriptor associated with file %s\n", filename);
			return (0);
		}
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
		char        *line;
		int            fd;
		int            ret;
		char        *filename;

		filename = "file";
		printf("enter the main");
		fd = open(filename, O_RDONLY);
		if (fd > 2)
		{
		if (close(fd) == 0)
		{
		line = NULL;
		printf("fd = %d\n", fd);
		ret = read(fd, line, BUFF_SIZE);
		printf("ret = %d\n", ret);
		ret = get_next_line(fd, &line);
		if (ret != -1)
		printf("-> must have returned '-1' when receiving a closed file descriptor\n");
		else
		printf("OK\n");
		}
		else
		{
		printf("An error occured while closing file descriptor associated with file %s\n", filename);
		return (0);
		}
		}
		else
		printf("An error occured while opening file %s\n", filename);
*/		}
				}
	return (0);
}
