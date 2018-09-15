#include "pch.h"

#include "../Includes.h"
#include "gtest/gtest.h"

namespace {

	class CalculatorTest : public ::testing::Test {

	};

	TEST(Test, TestTest) 
	{
		EXPECT_EQ(countFigures(), 0);
	}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}