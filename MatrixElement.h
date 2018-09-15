#pragma once

struct MatrixElement
{
	size_t row;
	size_t col;

	MatrixElement(size_t row = 0, size_t col = 0)
		: row(row)
		, col(col)
	{
	}
};