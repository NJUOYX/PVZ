#include"pch.h"
#include"GameSys.h"

GameLoader gloader;
GameSys sys(gloader);
TEST(GameSysTest, Fill_Staff) {
	Staff* stfs[COL_INDEX_MAX + 1];
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i)
		stfs[i] = new Staff;
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i) {
		EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,i }, stfs[i]));
		EXPECT_EQ(&sys.view_staff({ ROW_INDEX_MIN,i }), stfs[i]);
	}
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i)
		EXPECT_NO_THROW(delete stfs[i]);
}

TEST(GameSysTest, Del_Staff) {
	Staff* stfs[COL_INDEX_MAX + 1];
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i)
		stfs[i] = new Staff;
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i) {
		EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,i }, stfs[i]));
		EXPECT_NO_THROW(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }));
		EXPECT_NO_THROW(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }));
		EXPECT_FALSE(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }));
		EXPECT_ANY_THROW(delete stfs[i]);
	}
	
}

