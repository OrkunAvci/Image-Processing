#include <stdio.h>
#include <stdlib.h>

#include "pgmmanager.h"
#include "imgmanipulation.h"


int main()
{
	PGM* pgm = read_pgm("D:\\GitHub\\Image Processing\\Read PGM\\dog.pgm");

	PGM* output = spatial_lowpass(pgm, 5);

	output_pgm(output);
	write_pgm(output);

	clean_up_pgm(pgm);
	clean_up_pgm(output);

	system("pause");
	return 0;
}