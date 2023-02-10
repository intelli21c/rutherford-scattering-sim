#include "includes.h"
#include "common.h"

void spwrapper(int x) //edit this
{
	singleparticle(5000, 0.01, NULL, -100, x, 10, 0);
}

int main(int argc, char* argv[])
{
	//parse options for configuration
	//run
	for (int i = 0; i < 10; i++)
	{
		spwrapper(i);
	}
}