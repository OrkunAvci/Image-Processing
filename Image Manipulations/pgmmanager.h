#pragma once
#ifndef __PGMMANAGER_H__
#define __PGMMANAGER_H__

#include "pgmtype.h"	//	Includes stdio, stdlib, string.h

void verify_pgm_file(FILE*);

PGM* read_pgm(FILE*);

void write_pgm(PGM*);

void clean_up_pgm(PGM*);

void output_pgm(PGM*);

PGM* make_copy(PGM*);

#endif // !__PGMMANAGER_H__
