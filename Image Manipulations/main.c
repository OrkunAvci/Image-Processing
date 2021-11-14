#include <stdio.h>
#include <stdlib.h>

#include "pgmmanager.h"
#include "imgmanipulation.h"


int main()
{
	PGM* pgm = read_pgm("D:\\GitHub\\Image Processing\\Read PGM\\LanaDelRey.pgm");

	PGM* output;
	mirror_y(pgm);

	write_pgm(pgm);

	clean_up_pgm(pgm);
	//clean_up_pgm(output);

	system("pause");
	return 0;
}