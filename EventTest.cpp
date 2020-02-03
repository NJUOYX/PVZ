#include"pch.h"
#include"blank.h"

TEST(EventTest, Staff_Fill) {
	Blank blank;
	auto std = new Staff;
	EXPECT_NO_THROW(blank.fill_staff(std));
	EXPECT_EQ(blank.staff_in_this_blank, std);
}

TEST(EventTest, Staff_Del) {
	Blank blank;
	auto std = new Staff;
	EXPECT_NO_THROW(blank.fill_staff(std));
	EXPECT_NO_THROW(blank.del_staff());
	EXPECT_NO_THROW(blank.del_staff());
	EXPECT_EQ(blank.del_staff(),INT_RETURN_FALSE);
}