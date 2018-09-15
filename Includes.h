#pragma once
#include <vector>

unsigned int countFigures(std::vector<std::vector<bool>>& matrix)
{
	if ( 0 == matrix.size() || 0 == matrix[0].size())
	{
		return 0;
	}

	std::vector<std::vector<bool>> isVisited(matrix.size(), std::vector<bool>(matrix[0].size(), false));


	return 3;
}