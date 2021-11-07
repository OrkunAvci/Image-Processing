#pragma once
#ifndef __IMGMANIPULATION_H__
#define __IMGMANIPULATION_H__

#include "pgmmanager.h"	//	Includes pgmtype
#include "filtertype.h"	//	

void rotate_clockwise(PGM*);
void rotate_anticlockwise(PGM*);
void flip(PGM*);

void mirror_x(PGM*);
void mirror_y(PGM*);

void spatial_lowpass(PGM*);
void spatial_highpass(PGM*);
void spatial_weigthed_pass(PGM*);

#endif // !__IMGMANIPULATION_H__
