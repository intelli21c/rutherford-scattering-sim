#include "includes.h"
#include <io.h>

std::ofstream* makeoutputfile(std::ofstream* f, char* name = NULL)
{
	char namemem[16] = { 'o', 'u', 't', '0', '.', 'c', 's', 'v', 0 };
	char namenumstr[7] = { 0 };
	int outctr = 0;
	if (name == NULL)
	{
		while (access(namemem, 0) != -1) //F_OK==0
		{
			strcpy(namemem, "out");
			outctr++;
			strcat(namemem, strcat(itoa(outctr, namenumstr, 10), ".csv"));
		}
		f->open(namemem, std::ios::out);
	}
	else
	{
		if (!access(name, 0)) f->open(namemem, std::ios::out);
	}
	return f;
}