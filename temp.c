#include "get_next_line.h"

int null_check_gnl(char *file)
{
// #ifdef STRICT_MEM
	int fd = open(file, O_RDONLY);
	int lines = 0;
	reset_malloc_mock();
	char *res;
	do
	{
		res = get_next_line(fd);
		lines++;
	} while (res != NULL && lines < 20);
	close(fd);
	int result = 1;
	t_node *allocs = get_all_allocs();
	int total = reset_malloc_mock();
	int offset = g_offset;
	for (int i = 0; i < total; i++)
	{
		offset = sprintf(
					 signature + g_offset,
					 ":\n" MAG "malloc " NC "protection check for %ith malloc:\n",
					 i + 1) +
				 g_offset;
		add_trace_to_signature(offset, allocs, i);
		malloc_set_null(i);

		int count = 0;
		int fd = open(file, O_RDONLY);
		do
		{
			res = get_next_line(fd);
			free(res);
			if (res != NULL)
				count++;
		} while (res != NULL && count < 20);
		close(fd);
		result = check_leaks(NULL) && result;
		do
		{
			res = get_next_line(fd);
		} while (res != NULL);
		if (lines == count)
			result = error("Should exit early and return NULL\n");
	}
	show_res(result, "_NULL_CHECK");
	return result;
// #else
// 	(void)file;
// 	return 1;
// #endif
}
