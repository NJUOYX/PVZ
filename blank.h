#pragma once
#include"pch.h"
#include"Staff.h"

constexpr auto BLANK_VIEW_STAFF = "Blank::view_staff()";
constexpr auto DOUBLE_DELETE = "Double delete";

class Call_Info:public Info {
public:
	Call_Info():Info(){}
	Call_Info(Info info):Info(info){}
	Info get_Info()const { return info; }
};

class Blank_Sys_Call {
public:
	virtual Call_Info normal_sys_call() = 0;
	virtual Call_Info try_attack(Event*sender,Damage damage) = 0;
};

class Fail_Blank :public Event {
public:
	Fail_Blank() = default;
	void event_exc()override {

	}
	int fill_staff(Staff* staff)override {
		return INT_RETURN_FALSE;
	}
	int del_staff()override {
		return INT_RETURN_FALSE;
	}
	Staff const& view_staff()const override//may throw exception
	{
		return *new Standard();
	}
};

class Blank :public Event ,public Blank_Call{
public:
	Blank();
	Blank(Blank_Sys_Call* sys_ptr);
	void load_sys(Blank_Sys_Call* sys_ptr)override;
	~Blank();
	void event_exc()override;
	int fill_staff(Staff *staff)override;
	int del_staff()override;
	Staff const& view_staff()const override;//may throw exception
	Call_Info do_damage_to_me(Damage damage)override;
public:
	Blank_Call_Info normal_call()override;
	Blank_Call_Info normal_attack(Damage damage)override;
private:
	Staff* staff_in_this_blank;
	Blank_Sys_Call* sys_ptr;
};