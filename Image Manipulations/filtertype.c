#include "filtertype.h"

FT* create_filter()
{
	FT* created = calloc(1, sizeof(FT));
	if (created == NULL)	{	exit(1);	}
	return created;
}

void delete_filter(FT* deleted)
{
	if (deleted == NULL)	{	return;		}
	reset_filter(deleted);
	free(deleted);
}

void reset_filter(FT* filter)
{
	if (filter == NULL)	{	return;		}
	unsigned int i;
	for (i = 0; i < filter->size; i++)	{	free(filter->filter[i]);	}
	free(filter->filter);
}

void initialize(FT* filter, unsigned int size)
{
	if (filter == NULL)			{	return;		}
	if (filter->filter != NULL)	{	reset_filter(filter);	}
	
	unsigned int i;
	filter->size = size;
	filter->filter = calloc(size, sizeof(double*));
	if (filter->filter == NULL)	{	exit(1);	}
	for (i = 0; i < filter->size; i++)
	{
		filter->filter[i] = calloc(size, sizeof(double));
		if (filter->filter[i] == NULL)	{	exit(1);	}
	}
}


void set_roi_single(FT* filter, PGM* pgm, unsigned int dist)
{
	if (filter == NULL || pgm == NULL)	{	return;		}
	if (dist < 0 || pgm->width < dist || pgm->height < dist)	{	return;		}

	filter->roi_x_start = dist;
	filter->roi_x_end = pgm->width - dist;
	filter->roi_y_start = dist;
	filter->roi_y_end = pgm->height - dist;
}

void set_roi_double(FT* filter, PGM* pgm, unsigned int dist_x, unsigned int dist_y)
{
	if (filter == NULL || pgm == NULL)	{	return;		}
	if (dist_x < 0 || dist_y < 0 || pgm->width < dist_x || pgm->height < dist_y)	{	return;		}

	filter->roi_x_start = dist_x;
	filter->roi_x_end = pgm->width - dist_x;
	filter->roi_y_start = dist_y;
	filter->roi_y_end = pgm->height - dist_y;
}

void set_roi_quad(FT* filter, PGM* pgm, unsigned int dist_x_start, unsigned int dist_x_end, unsigned int dist_y_start, unsigned int dist_y_end)
{
	if (filter == NULL || pgm == NULL)	{	return;		}
	if (dist_x_start < 0 || dist_y_start < 0 || pgm->width < dist_x_end || pgm->height < dist_y_end)	{	return;		}

	filter->roi_x_start = dist_x_start;
	filter->roi_x_end = pgm->width - dist_x_end;
	filter->roi_y_start = dist_y_start;
	filter->roi_y_end = pgm->height - dist_y_end;
}
