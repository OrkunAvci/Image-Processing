#pragma once
#include "imgmanipulation.h"

void rotate_clockwise(PGM* pgm)
{
	if (pgm == NULL)	{	return;		}
	if (pgm->height != pgm->width)	{	return;		}

	unsigned int i, j, temp;
	for (i = 0; i < pgm->height / 2; i++)
	{
		for (j = i; j < pgm->height - i - 1; j++)
		{
			temp = pgm->data[i][j];
			pgm->data[i][j] = pgm->data[pgm->height - 1 - j][i];
			pgm->data[pgm->height - 1 - j][i] = pgm->data[pgm->height - 1 - i][pgm->height - 1 - j];
			pgm->data[pgm->height - 1 - i][pgm->height - 1 - j] = pgm->data[j][pgm->height - 1 - i];
			pgm->data[j][pgm->height - 1 - i] = temp;
		}
	}
}

void rotate_anticlockwise(PGM* pgm)
{
	if (pgm == NULL)	{	return;		}
	if (pgm->height != pgm->width)	{	return;		}

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
	rotate_clockwise(pgm);
	rotate_clockwise(pgm);
}

void mirror_x(PGM* pgm)
{
	if (pgm == NULL)	{	return;		}

	unsigned int i, j, temp;
	for (i = 0; i < pgm->height; i++)
	{
		for (j = 0; j < pgm->width / 2; j++)
		{
			temp = pgm->data[i][j];
			pgm->data[i][j] = pgm->data[i][pgm->width - j - 1];
			pgm->data[i][pgm->width - j - 1] = temp;
		}
	}
}

void mirror_y(PGM* pgm)
{
	if (pgm == NULL)	{	return;		}

	unsigned int i, j, temp;
	for (i = 0; i < pgm->width; i++)
	{
		for (j = 0; j < pgm->height / 2; j++)
		{
			temp = pgm->data[j][i];
			pgm->data[j][i] = pgm->data[pgm->width - j - 1][i];
			pgm->data[pgm->width - j - 1][i] = temp;
		}
	}
}

PGM* spatial_lowpass(PGM* pgm, unsigned int filter_size)
{
	FT* filter = create_filter();
	initialize(filter, filter_size);

	unsigned int i, j;
	for (i = 0; i < filter->size; i++)
	{
		for (j = 0; j < filter->size; j++)
		{
			filter->filter[i][j] = 1;
		}
	}
	set_roi_single(filter, pgm, 0);
	filter->multiplier = 1;
	filter->divider = filter->size * filter->size;

	PGM* out = make_copy(pgm);

	int k, l;
	double sum;
	for (i = (filter->size + 1) / 2; i < pgm->height - ((filter->size + 1) / 2); i++)
	{
		for (j = (filter->size + 1) / 2; j < pgm->width - ((filter->size + 1) / 2); j++)
		{
			sum = 0.0;
			for (k = (-1) * (((int)filter->size) / 2); k < ((int)filter->size) / 2; k++)
			{
				for (l = (-1) * (((int)filter->size) / 2); l < ((int)filter->size) / 2; l++)
				{
					sum = sum + (double)pgm->data[i + k][j + l];
				}
			}
			sum = sum * filter->multiplier;
			sum = sum / filter->divider;
			out->data[i][j] = (unsigned int)sum;
		}
	}

	return out;
}

PGM* spatial_highpass(PGM* pgm)
{
	//	---
}

PGM* spatial_weigthed_pass(PGM* pgm)
{
	//	---
}
