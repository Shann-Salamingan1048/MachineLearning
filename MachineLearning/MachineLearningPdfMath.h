#pragma once
#include "global.h"
#include "Matrices.h"
#include "Vectors.h"

class MachineLearningPdfMath
{
public:
	void Run()
	{
		Vec4d v1{ 1,1,1,1 };
		Vec4d v2{ 2,2,2,2 };
		const auto result = v1 * v2;
		printVec4(result);
	}

private:
	
};