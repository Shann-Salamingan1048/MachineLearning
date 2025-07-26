#pragma once
#include "global.h"
#include "Matrices.h"


class MachineLearningPdfMath
{
public:
	void Run()
	{
		const Matrix4di a = {
			{1,2,3,4},
			{5,6,7,4},
			{14,2,3,21},
			{54,2,3,3},
		};
		const Matrix4di b = {
			{11,2,3,4},
			{12,6,74,4},
			{3,2,31,251},
			{46,23,3,34},
		};

		const auto c = a * b;

		printMatrix(c);
	}

private:
	
};