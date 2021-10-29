#pragma once
#include "imgmanipulation.h"

void rotate_clockwise(PGM* pgm)
{
	
}

void rotate_anticlockwise(PGM* pgm)
{
	if (pgm->height != pgm->width) { return; }

	unsigned int i, j, temp;
	for (i = 0; i < pgm->height / 2; i++)
	{
		for (j = i; j < pgm->height - i - 1; j++)
		{
			temp = pgm->data[i][j];
			pgm->data[i][j] = pgm->data[j][pgm->height - 1 - i];
			pgm->data[j][pgm->height - 1 - i] = pgm->data[pgm->height - 1 - i][pgm->height - 1 - j];
			pgm->data[pgm->height - 1 - i][pgm->height - 1 - j] = pgm->data[pgm->height - 1 - j][i];
			pgm->data[pgm->height - 1 - j][i] = temp;
		}
	}
}

void flip(PGM* pgm)
{
	
}

void mirror_x(PGM* pgm)
{
	
}

void mirror_y(PGM* pgm)
{
	
}

void spatial_lowpass(PGM* pgm)
{
	
}

void spatial_highpass(PGM* pgm)
{
	
}

void spatial_weigthed_pass(PGM* pgm)
{
	
}
