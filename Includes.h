#pragma once
#include <vector>
#include <queue>
#include "MatrixElement.h"

void lookAround(const MatrixElement& startingElement,
				const std::vector<std::vector<bool>>& matrix,
				std::vector<std::vector<bool>>& isVisited)
{
	size_t cntRows = matrix.size();
	size_t cntCols = matrix[0].size();

	std::queue<MatrixElement> elementsQueue;
	elementsQueue.push(startingElement);

	while (!elementsQueue.empty())
	{
		MatrixElement& currentElement = elementsQueue.front();

		// look left
		if (currentElement.col > 0 && 
			matrix[currentElement.row][currentElement.col - 1] && 
			!isVisited[currentElement.row][currentElement.col - 1])
		{
			elementsQueue.push(MatrixElement(currentElement.row, currentElement.col - 1));
		}
		
		// look right
		if (currentElement.col < cntCols - 1 &&
			matrix[currentElement.row][currentElement.col + 1] &&
			!isVisited[currentElement.row][currentElement.col + 1])
		{
			elementsQueue.push(MatrixElement(currentElement.row, currentElement.col + 1));
		}

		// look up
		if (currentElement.row > 0 &&
			matrix[currentElement.row - 1][currentElement.col] &&
			!isVisited[currentElement.row - 1][currentElement.col])
		{
			elementsQueue.push(MatrixElement(currentElement.row - 1, currentElement.col));
		}

		// look down
		if (currentElement.row < cntRows - 1 &&
			matrix[currentElement.row + 1][currentElement.col] &&
			!isVisited[currentElement.row + 1][currentElement.col])
		{
			elementsQueue.push(MatrixElement(currentElement.row + 1, currentElement.col));
		}

		isVisited[currentElement.row][currentElement.col] = true;
		elementsQueue.pop();
	}
}

unsigned int countFigures(const std::vector<std::vector<bool>>& matrix)
{
	if (0 == matrix.size() || 0 == matrix[0].size())
	{
		return 0;
	}

	unsigned int cntFigures = 0;

	size_t rows = matrix.size();
	size_t cols = matrix[0].size();

	std::vector<std::vector<bool>> isVisited(matrix.size(), std::vector<bool>(matrix[0].size(), false));

	for (size_t currentRow = 0; currentRow < rows; ++currentRow)
	{
		for (size_t currentCol = 0; currentCol < cols; ++currentCol)
		{
			if (matrix[currentRow][currentCol] && !isVisited[currentRow][currentCol])
			{
				lookAround(MatrixElement(currentRow, currentCol), matrix, isVisited);
				++cntFigures;
			}
		}
	}

	return cntFigures;
}