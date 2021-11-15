#include "pgmmanager.h"

void verify_pgm_file(FILE* file)
{
	char type[3] = { '\0' };
	fscanf(file, "%s", type);
	fseek(file, 0, SEEK_SET);
	if (strncmp(type, "P5", 2) && strncmp(type, "P2", 2))	{	exit(2);	}
}

void skip_comments(FILE* file)
{
	int ch;
	char line[100];

	while ( ( ch = fgetc(file) ) != EOF && isspace(ch) );

	if (ch == '#')
	{
		fgets(line, sizeof(line), file);
		skip_comments(file);
	}
	else
	{
		fseek(file, -1, SEEK_CUR);
	}
}

void read_p2(PGM* pgm, FILE* file)
{
	pgm->data = calloc(pgm->height, sizeof(unsigned char*));
	if (pgm->data == NULL) { return  NULL; }

	unsigned int i, j;
	int dummy;
	for (i = 0; i < pgm->height; i++)
	{
		pgm->data[i] = calloc(pgm->width, sizeof(unsigned char));
		if (pgm->data[i] == NULL) { return  NULL; }

		for (j = 0; j < pgm->width; j++)
		{
			fscanf(file, "%d", &dummy);
			pgm->data[i][j] = (unsigned char)dummy;
		}
	}
}

void read_p5(PGM* pgm, FILE* file)
{
	pgm->data = calloc(pgm->height, sizeof(unsigned char*));
	if (pgm->data == NULL) { return  NULL; }

	unsigned int i;
	for (i = 0; i < pgm->height; i++)
	{
		pgm->data[i] = calloc(pgm->width, sizeof(unsigned char));
		if (pgm->data[i] == NULL) { return  NULL; }

		fread(pgm->data[i], sizeof(unsigned char), pgm->width, file);
	}
}

PGM* read_pgm(const char* fileName)
{
	PGM* pgm = create_pgm(fileName);

	FILE* file = fopen(pgm->file_name, "rb");
	if (file == NULL)	{	exit(1); }

	verify_pgm_file(file);

	skip_comments(file);
	fscanf(file, "%s", pgm->type);
	skip_comments(file);

	fscanf(file, "%d %d", &(pgm->width), &(pgm->height));
	skip_comments(file);

	fscanf(file, "%d", &(pgm->maxValue));
	skip_comments(file);

	if	  (pgm->type[1] == '2')		{	read_p2(pgm, file);		}
	else/*(pgm->type[1] == '5')*/	{	read_p5(pgm, file);		}

	fclose(file);

	return pgm;
}

void write_p2(PGM* pgm, FILE* out)
{
	unsigned int i, j;
	for (i = 0; i < pgm->height; i++)
	{
		for (j = 0; j < pgm->width; j++)
		{
			fprintf(out, "%d ", (int)pgm->data[i][j]);
		}
	}
}

void write_p5(PGM* pgm, FILE* out)
{
	unsigned int i, j;
	for (i = 0; i < pgm->height; i++)
	{
		for (j = 0; j < pgm->width; j++)
		{
			fwrite(&(pgm->data[i][j]), sizeof(unsigned char), 1, out);
		}
	}
}

void write_pgm(PGM* pgm)
{
	FILE* out = fopen("out.pgm", "w");
	if (out == NULL)	{	exit(1);	}
	fclose(out);

	out = fopen("out.pgm", "ab");
	fwrite(pgm->type, sizeof(char), 2, out);
	fwrite("\n", sizeof(char), 1, out);
	fprintf(out, "%u %u\n", pgm->width, pgm->height);
	fprintf(out, "%u\n", (pgm->maxValue));

	if	  (pgm->type[1] == '2')		{	write_p2(pgm, out);		}
	else/*(pgm->type[1] == '5')*/	{	write_p5(pgm, out);		}

	fclose(out);
}

void clean_up_pgm(PGM* pgm)
{
	if (pgm == NULL)	{	return;		}
	delete_pgm(pgm);
}

void output_pgm(PGM* pgm)
{
	unsigned int i, j;
	printf("Type: %s\n", pgm->type);
	printf("Height: %d\n", pgm->height);
	printf("Width: %d\n", pgm->width);
	printf("Max Value: %d\n", pgm->maxValue);
	for (i = 0; i < pgm->height; i++)
	{
		for (j = 0; j < pgm->width; j++)
		{
			printf("%c", pgm->data[i][j]);
		}
		printf("\n");
	}
}

PGM* make_copy(PGM* original)
{
	PGM* copy = calloc(1, sizeof(PGM));
	if (copy == NULL)	{	exit(1);	}
	
	copy->height = original->height;
	copy->width = original->width;
	copy->maxValue = original->maxValue;

	copy->file_name = calloc( strlen(original->file_name) + 1, sizeof(char));
	if (copy->file_name == NULL)	{	exit(1);	}
	strncpy(copy->file_name, original->file_name, strlen(original->file_name));

	strncpy(copy->type, original->type, strlen(original->type));

	unsigned int i, j;
	copy->data = calloc(copy->height, sizeof(unsigned char*));
	if (copy->data == NULL)	{	exit(1);	}
	for (i = 0; i < copy->height; i++)
	{
		copy->data[i] = calloc(copy->width, sizeof(unsigned char));
		if (copy->data[i] == NULL)	{	exit(1);	}
		for (j = 0; j < copy->width; j++)
		{
			copy->data[i][j] = original->data[i][j];
		}
	}

	return copy;
}