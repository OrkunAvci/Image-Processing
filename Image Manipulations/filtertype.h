#pragma once
#ifndef __FILTERTYPE_H__
#define __FILTERTYPE_H__

#include <stdlib.h>

#include "pgmtype.h"

typedef struct FilterType
{
	unsigned int roi_x_start;
	unsigned int roi_x_end;
	unsigned int roi_y_start;
	unsigned int roi_y_end;
	unsigned int multiplier;
	unsigned int divider;
	unsigned int size;
	double** filter;
} FT;

FT* create_filter();
void delete_filter(FT*);

void reset_filter(FT*);
void initialize(FT*, unsigned int);

void set_roi_single(FT*, PGM*, unsigned int);
void set_roi_double(FT*, PGM*, unsigned int, unsigned int);
void set_roi_quad(FT*, PGM*, unsigned int, unsigned int, unsigned int, unsigned int);

#endif // !__FILTERTYPE_H__
