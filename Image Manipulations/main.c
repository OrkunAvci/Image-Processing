#include <stdio.h>
#include <stdlib.h>

#include "pgmmanager.h"
#include "imgmanipulation.h"


int main()
{
	PGM* pgm = read_pgm("D:\\GitHub\\Image Processing\\Read PGM\\LanaDelRey.pgm");

	rotate_clockwise(pgm);

	write_pgm(pgm);

	clean_up_pgm(pgm);

	system("pause");
	return 0;
}