#include "includes.h"
#include "common.h"

#include <iostream>
#include <fstream>

int scale = 100;

const int au = 79;
const int he = 2;

float ax(float x, float y)
{
	return 100 * x / sqrt(pow((pow(x, 2) + pow(y, 2)), 3));
	//return  scale * au * he * x / (4 * PI * E0 * sqrt(pow((pow(x, 2) + pow(y, 2)), 3)));
}

float ay(float x, float y)
{
	return 100 * y / sqrt(pow((pow(x, 2) + pow(y, 2)), 3));
}

float vf(float v)
{
	return v;
}

void singleparticle(int iter, float res, char* name, float alpx, float alpy, float alpvx, float alpvy)
{
	std::ofstream f;
	makeoutputfile(&f);
	if (!f.is_open()) std::cout << "file not open...\n";
	f << "x, y, vx, vy\n";
	f << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";

	float k[4][4] = { 0 }; //k1234 for x, y, vx, vy
	for (int i = 0; i < iter; i++)
	{
		k[0][0] = vf(alpvx);
		k[0][1] = vf(alpvy);
		k[0][2] = ax(alpx, alpy);
		k[0][3] = ay(alpx, alpy);

		k[1][0] = vf(alpvx + k[0][2] / 2);
		k[1][1] = vf(alpvy + k[0][3] / 2);
		k[1][2] = ax(alpx + k[0][0] / 2, alpy + k[0][1] / 2);
		k[1][3] = ay(alpx + k[0][0] / 2, alpy + k[0][1] / 2);

		k[1][0] = vf(alpvx + k[1][2] / 2);
		k[1][1] = vf(alpvy + k[1][3] / 2);
		k[1][2] = ax(alpx + k[1][0] / 2, alpy + k[1][1] / 2);
		k[1][3] = ay(alpx + k[1][0] / 2, alpy + k[1][1] / 2);

		k[1][0] = vf(alpvx + k[2][2]);
		k[1][1] = vf(alpvy + k[2][3]);
		k[1][2] = ax(alpx + k[2][0], alpy + k[2][1]);
		k[1][3] = ay(alpx + k[2][0], alpy + k[2][1]);

		alpx += (k[0][0] + 2 * k[1][0] + 2 * k[2][0] + k[3][0]) * res / 6;
		alpy += (k[0][1] + 2 * k[1][1] + 2 * k[2][1] + k[3][1]) * res / 6;
		alpvx += (k[1][2] + 2 * k[1][2] + 2 * k[2][2] + k[3][2]) * res / 6;
		alpvy += (k[0][3] + 2 * k[1][3] + 2 * k[2][3] + k[3][3]) * res / 6;

		f << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";

		std::cout << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";
	}
	std::cout << "done!\n";
	f.close();
}

const float atomrad_ts = 10;

float ax_ts(float x, float y)
{
	return (pow(x, 2) + (pow(y, 2)) > pow(atomrad_ts, 2)) ? (100 * x / sqrt(pow((pow(x, 2) + pow(y, 2)), 3)))\
		: (x / 10);
}

float ay_ts(float x, float y)
{
	return (pow(x, 2) + (pow(y, 2)) > pow(atomrad_ts, 2)) ? (100 * y / sqrt(pow((pow(x, 2) + pow(y, 2)), 3)))\
		: (y / 10);
}

void thompsonsingle()
{
	float alpx = -100;
	float alpy = 1;
	float alpvx = 10;
	float alpvy = 0;

	float k[4][4] = { 0 }; //k1234 for x, y, vx, vy

	int iter = 5000;
	float res = 0.01;


	std::ofstream f;
	f.open("out3.csv", std::ios::out);
	if (!f.is_open()) std::cout << "fuck\n";
	//getchar();
	f << "x, y, vx, vy\n";
	f << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";

	std::cout << "x, y, vx, vy\n";
	std::cout << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";
	for (int i = 0; i < iter; i++)
	{
		k[0][0] = vf(alpvx);
		k[0][1] = vf(alpvy);
		k[0][2] = ax_ts(alpx, alpy);
		k[0][3] = ay_ts(alpx, alpy);

		k[1][0] = vf(alpvx + k[0][2] / 2);
		k[1][1] = vf(alpvy + k[0][3] / 2);
		k[1][2] = ax_ts(alpx + k[0][0] / 2, alpy + k[0][1] / 2);
		k[1][3] = ay_ts(alpx + k[0][0] / 2, alpy + k[0][1] / 2);

		k[1][0] = vf(alpvx + k[1][2] / 2);
		k[1][1] = vf(alpvy + k[1][3] / 2);
		k[1][2] = ax_ts(alpx + k[1][0] / 2, alpy + k[1][1] / 2);
		k[1][3] = ay_ts(alpx + k[1][0] / 2, alpy + k[1][1] / 2);

		k[1][0] = vf(alpvx + k[2][2]);
		k[1][1] = vf(alpvy + k[2][3]);
		k[1][2] = ax_ts(alpx + k[2][0], alpy + k[2][1]);
		k[1][3] = ay_ts(alpx + k[2][0], alpy + k[2][1]);

		alpx += (k[0][0] + 2 * k[1][0] + 2 * k[2][0] + k[3][0]) * res / 6;
		alpy += (k[0][1] + 2 * k[1][1] + 2 * k[2][1] + k[3][1]) * res / 6;
		alpvx += (k[1][2] + 2 * k[1][2] + 2 * k[2][2] + k[3][2]) * res / 6;
		alpvy += (k[0][3] + 2 * k[1][3] + 2 * k[2][3] + k[3][3]) * res / 6;

		f << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";

		std::cout << alpx << ", " << alpy << ", " << alpvx << ", " << alpvx << "\n";
	}
	f.close();
}