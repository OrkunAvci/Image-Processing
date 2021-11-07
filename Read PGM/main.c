#include <stdio.h>
#include <stdlib.h>

#include "pgmmanager.h"

int main()
{
	PGM* pgm = read_pgm("D:\\GitHub\\Image Processing\\Read PGM\\LanaDelRey.pgm");

	output_pgm(pgm);
	write_pgm(pgm);

	clean_up_pgm(pgm);
	system("pause");
	return 0;
}