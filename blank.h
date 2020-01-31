#pragma once
#include"pch.h"
#include"Staff.h"
class Blank :public Event {
public:
	Blank()=default;
	int fill_staff(Staff *staff);
	int del_staff();
	Staff const& view_staff()const;
private:
	Staff* staff_in_this_blank;
};