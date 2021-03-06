#include <iostream>
#include <string>
#include <regex>
#include "CountFigures.h"

void input(size_t& number)
{
	while (true)
	{
		std::string input;
		std::cin >> input;
		std::regex integer("[[:digit:]]+");
		if (regex_match(input, integer))
		{
			number = std::stoul(input, nullptr);
			break;
		}
		std::cout << "Oops, wrong input :/ Please, enter a positive integer: ";
	}
}

int main()
{
	size_t rows = 0;
	size_t cols = 0;
	std::cout << "Welcome to FigureCounter! \nPlease, enter number of rows and columns of the table:\nRows: ";
	input(rows);
	
	std::cout << "Colums: ";
	input(cols);

	std::vector<std::vector<bool>> matrix(rows, std::vector<bool>(cols, false));

	std::cout << "Thank you! I'll now need the table. Please, enter " << rows * cols << " 0s and 1s (1 means marked).\n";
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			while (true)
			{
				std::string input;
				std::cin >> input;
				if ("0" == input)
				{
					break;
				}
				else if ("1" == input)
				{
					matrix[i][j] = true;
					break;
				}
				std::cout << "Oops... wrong input :/ Please, enter 0 or 1.\n";
			}
		}
	}

	unsigned int result = countFigures(matrix);
	std::cout << "The number of figures in the matrix is " << result << ". Thank you!\n";

	return 0;
}
