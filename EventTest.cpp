#include"pch.h"
#include"blank.h"

TEST(EventTest, Staff_Fill) {
	Blank blank;
	auto std = new Staff;
	EXPECT_NO_THROW(blank.fill_staff(std));
	EXPECT_EQ(blank.staff_in_this_blank, std);
	EXPECT_NO_THROW(delete blank.staff_in_this_blank);
}

TEST(EventTest, Staff_Del) {
	Blank blank;
	auto std = new Staff;
	EXPECT_NO_THROW(blank.fill_staff(std));
	EXPECT_NO_THROW(blank.del_staff());
	EXPECT_NO_THROW(blank.del_staff());
	EXPECT_FALSE(blank.del_staff());
	EXPECT_ANY_THROW(delete std);
}