/*
 * toolc.c
 *
 *  Created on: 27.08.2022
 *      Author: mf
 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>

long int get_filesize(const char* filename)
{
	struct stat st;
	if (stat(filename, &st) == 0)
	{
		return (long int)(st.st_size);
	}
	else
	{
		//print_errno(filename);
		return -1;
	}
}

char* file_to_mem(const char* filename, int* size)
{
	int filesize = get_filesize(filename);

    char* buf = (char*)malloc(filesize);

	FILE* file = fopen(filename, "rb");
	*size = -1;
	if (file)
	{
		*size = fread(buf, sizeof(char), filesize, file);
		fclose(file);
		file = NULL;
	}

	//free(buf);
	return buf;
}

#include <ctype.h>

char *strtriml(char *str)
{
	while(isspace(*str)) str++;
	return str;
}

void strtrimr(char *str)
{
	int n = strlen(str) - 1;

	while (n > 0)
	{
		if (isspace(str[n]))
		{
			str[n] = '\0';
			n--;
		}
		else
			break;
	}
}

char *strtrim(char *str)
{
	str = strtriml(str);
	strtrimr(str);
	return str;
}

