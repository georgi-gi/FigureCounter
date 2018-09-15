#include "pch.h"

#include "../Includes.h"
#include "gtest/gtest.h"

namespace {

	TEST(CountFiguresTest, BasicTest) 
	{
		std::vector<std::vector<bool>> testMatrix = 
			{ 
				{ true,	 false, false, false, false },
				{ true,  false, true,  true,  false },
				{ false, true,  false, true,  false },
				{ false, true,  true,  true,  false },
				{ false, false, false, false, true }
			};

		EXPECT_EQ(countFigures(testMatrix), 3);
	}

	TEST(CountFiguresTest, Empty)
	{
		std::vector<std::vector<bool>> testMatrix;

		EXPECT_EQ(countFigures(testMatrix), 0);
	}

	TEST(CountFiguresTest, NoFigures)
	{
		std::vector<std::vector<bool>> testMatrix =
		{
			{ false, false, false, false, false },
			{ false, false, false, false, false },
			{ false, false, false, false, false },
			{ false, false, false, false, false },
			{ false, false, false, false, false }
		};

		EXPECT_EQ(countFigures(testMatrix), 0);
	}

	TEST(CountFiguresTest, AllMarked)
	{
		std::vector<std::vector<bool>> testMatrix =
		{
			{ true, true},
			{ true, true}
		};

		EXPECT_EQ(countFigures(testMatrix), 1);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}