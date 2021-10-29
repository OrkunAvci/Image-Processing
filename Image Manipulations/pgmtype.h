#pragma once
#ifndef __PGMTYPE_H__
#define __PGMTYPE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PGM
{
	char* file_name;
	char type[3];
	unsigned int height;
	unsigned int width;
	unsigned int maxValue;
	unsigned char** data;
}PGM;

PGM* create_pgm(const char*);
void delete_pgm(PGM*);

#endif // !__PGMTYPE_H__

