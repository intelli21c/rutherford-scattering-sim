#pragma once
#ifndef COMMON_H
#define COMMON_H

#include "includes.h"

#define E0 8.9e-12f //8.85 10^12 Farad(=Coulomb/Volt)/Metre
#define QE 1.6e-19f //1.6 10^19 Coulombs

#ifndef PI
#define PI 3.14f
#endif // !PI


std::ofstream* makeoutputfile(std::ofstream* f, char* name = NULL);

void singleparticle(int iter = 5000, float res = 0.01, char* name = NULL, float alpx = -100, float alpy = 3, float alpvx = 10, float alpvy = 0);

#endif