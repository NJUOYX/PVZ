#pragma once
#include"pch.h"
#include"Staff.h"

constexpr auto BLANK_VIEW_STAFF = "Blank::view_staff()";
constexpr auto DOUBLE_DELETE = "Double delete";

using Call_Info = int;

class Blank_Sys_Call {
public:
	virtual Call_Info normal_sys_call() = 0;
	
};


class Blank :public Event {
public:
	Blank();
	~Blank();
	void event_exc()override;
	int fill_staff(Staff *staff)override;
	int del_staff()override;
	Staff const& view_staff()const override;//may throw exception
private:
	Staff* staff_in_this_blank;
};