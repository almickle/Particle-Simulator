#pragma once
#include <Eigen/Dense>

using namespace Eigen;

class Field
{
protected:
	Field()
	{

	}
protected:
	Matrix<Vector2f, Dynamic, Dynamic> matrix;
};

