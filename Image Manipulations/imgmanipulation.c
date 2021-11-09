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
	FT* filter = create_filter();
	initialize(filter, 3);

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
	for (i = filter->size + 1 / 2; i < pgm->height - (filter->size + 1 / 2); i++)
	{
		for (j = filter->size + 1 / 2; j < pgm->width - (filter->size + 1 / 2); j++)
		{
			double sum = 0.0;
			for (k = (-1) * (filter->size + 1 / 2); k < filter->size + 1 / 2; k++)
			{
				for (l = (-1) * (filter->size + 1 / 2); l < filter->size + 1 / 2; l++)
				{
					sum = sum + pgm->data[i + k][j + l];
				}
			}
			sum = sum * filter->multiplier;
			sum = sum / filter->divider;
			out->data[i][j] = (unsigned int)sum;
		}
	}

	write_pgm(out);
	clean_up_pgm(out);
}

void spatial_highpass(PGM* pgm)
{
	
}

void spatial_weigthed_pass(PGM* pgm)
{
	
}
