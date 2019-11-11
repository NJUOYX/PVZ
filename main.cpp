#include "pch.h"
#define DEBUG

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}




#ifdef DEBUG
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif

#ifdef RUN
int main(int argc, char** argv) {

	return 0;
}
#endif