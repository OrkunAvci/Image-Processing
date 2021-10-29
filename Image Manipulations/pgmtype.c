#pragma once
#include "pgmtype.h"

PGM* create_pgm(const char* fileName)
{
	PGM* created = calloc(1, sizeof(PGM));
	if (created == NULL)	{	exit(1);	}
	
	created->file_name = calloc( strlen(fileName) + 1 , sizeof(char) );
	if (created->file_name == NULL)	{	exit(1);	}
	
	strncpy(created->file_name, fileName, strlen(fileName));

	return created;
}

void delete_pgm(PGM* pgm)
{
	int i;
	for (i = 0; i < pgm->height; free(pgm->data[i++]));
	free(pgm->data);
	free(pgm->file_name);
	free(pgm);
}

