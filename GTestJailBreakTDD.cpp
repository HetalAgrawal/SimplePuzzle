// GTestJailBreakTDD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include <iostream>

int GetJumpCount(int meterAbleToJump, int meterFallAfterJump, int numOfWalls, int* arrHeightOfWalls)
{
	int numOfJump = 0, distanceRemaining = meterAbleToJump;
	for (int i = 0; i < numOfWalls; ++i)
	{
		int totalDistanceRemaining = arrHeightOfWalls[i];
		do
		{
			++numOfJump;
			totalDistanceRemaining -= meterAbleToJump;
			if (totalDistanceRemaining == 0) break;
			totalDistanceRemaining += meterFallAfterJump;
		}while(totalDistanceRemaining > 0);
	}
	return numOfJump;
}

TEST(JailBreakTest, JumpOneWall)
{
	int meterAbleToJump = 10;
	int meterFallAfterJump = 1;
	int size = 1;
	int heightOfWall[1];
	heightOfWall[0] = 10;
	EXPECT_EQ(1, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));

	meterAbleToJump = 8;
	EXPECT_EQ(2, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));

	meterAbleToJump = 3;
	EXPECT_EQ(5, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));

	meterAbleToJump = 5;
	heightOfWall[0] = 9;
	EXPECT_EQ(2, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));

	meterAbleToJump = 5;
	heightOfWall[0] = 10;
	EXPECT_EQ(3, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));
}

TEST(JailBreakTest, JumpTwoWalls)
{
	int meterAbleToJump = 5;
	int meterFallAfterJump = 1;
	int const size = 2;
	int heightOfWall[size];
	heightOfWall[0] = 9;
	heightOfWall[1] = 10;
	EXPECT_EQ(5, GetJumpCount(meterAbleToJump, meterFallAfterJump, size, heightOfWall));
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	int n = 0;
	std::cin >> n;
	return 0;
}

