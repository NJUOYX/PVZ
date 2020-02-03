#include"pch.h"
#include"GameSys.h"

TEST(GameSysTest, Fill_Staff) {
	GameLoader gloader;
	GameSys sys(gloader);
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
	GameLoader gloader;
	GameSys sys(gloader);
	Staff* stfs[COL_INDEX_MAX + 1];
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i)
		stfs[i] = new Staff();
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i) {
		EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,i }, stfs[i]));
		EXPECT_NO_THROW(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }));
		EXPECT_NO_THROW(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }));
		EXPECT_EQ(sys.del_staff_in_blank({ ROW_INDEX_MIN,i }),INT_RETURN_FALSE);
	}
}

TEST(GameSysTest, Pos_Set) {
	GameLoader gloader;
	GameSys sys(gloader);
	Staff* stfs[COL_INDEX_MAX + 1];
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i)
		stfs[i] = new Staff();
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i) {
		EXPECT_EQ(sys.fill_staff_in_blank({ ROW_INDEX_MIN,i }, stfs[i]),INT_RETURN_TRUE);
	}
	for (auto i = COL_INDEX_MIN; i < COL_INDEX_MAX; ++i) {
		EXPECT_EQ(&sys.view_staff({ ROW_INDEX_MIN,i }), stfs[i]);
	}
}

TEST(GameSysTest, Pos_Check) {
	GameLoader gloader;
	GameSys sys(gloader);
	Staff stf;
	for (auto i = -1000; i < 1000; ++i) {
		if (i >= COL_INDEX_MIN && i <= COL_INDEX_MAX)
			EXPECT_EQ(sys.fill_staff_in_blank({ ROW_INDEX_MIN, i },&stf), INT_RETURN_TRUE);
		else
			EXPECT_EQ(sys.fill_staff_in_blank({ ROW_INDEX_MIN, i }, &stf), INT_RETURN_FALSE);
	}
}

TEST(GameSysTest, normal_sys_call) {
	GameLoader gloader;
	GameSys sys(gloader);
	EXPECT_EQ(sys.normal_sys_call(), 1);
	Blank_Sys_Call* blank_interface(&sys);
	EXPECT_EQ(blank_interface->normal_sys_call(), 1);
}