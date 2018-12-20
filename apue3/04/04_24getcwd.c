#include "apue.h"

char *path_alloc(size_t* size)
{
	char *p = NULL;
	if(!size) 
		return NULL;
	p = malloc(256);
	if(p)
		*size = 256;
	else
		*size = 0;
	return p;
}
int
main(void)
{
	char *ptr;
	size_t size;
	// if(chdir("/usr/spool/uucppublic") < 0)
	// if(chdir("/usr/include") < 0)
	if(chdir("/home/lingyq") < 0)
		err_sys("chdir failed");
	ptr = path_alloc(&size); /* our own function */
		err_sys("getcwd failed");
	printf("cwd = %s\n",ptr);
	exit(0);
}