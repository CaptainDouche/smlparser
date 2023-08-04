/*
 * tools.h
 *
 *  Created on: 27.08.2022
 *      Author: mf
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include "defs.h"

long int get_filesize(const char* filename);
char* file_to_mem(const char* filename, int* size);

char *strtriml(char *str);
void strtrimr(char *str);
char *strtrim(char *str);

#endif /* TOOLS_H_ */
