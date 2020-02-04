#include "pch.h"
#include "blank.h"

Blank::Blank():staff_in_this_blank(nullptr)
{
}

Blank::Blank(Blank_Sys_Call* sys_ptr):sys_ptr(sys_ptr)
{
}

void Blank::load_sys(Blank_Sys_Call* sys_ptr)
{
	this->sys_ptr = sys_ptr;
}



Blank::~Blank()
{
	if (staff_in_this_blank != nullptr)
		delete staff_in_this_blank;
}

void Blank::event_exc()
{
	staff_in_this_blank->exc(this);
}

int Blank::fill_staff(Staff* staff)
{
	if (staff_in_this_blank == nullptr)
	{
		staff_in_this_blank = staff;
		return INT_RETURN_TRUE;
	}
	else
	{
		return INT_RETURN_FALSE;
	}
}

int Blank::del_staff()
{
	if (staff_in_this_blank == nullptr)
		return INT_RETURN_FALSE;
	else {
		delete staff_in_this_blank;
		staff_in_this_blank = nullptr;
		return INT_RETURN_TRUE;
	}
}

Staff const& Blank::view_staff() const
{
	if (staff_in_this_blank == nullptr)
	{
		auto res = std::string(BLANK_VIEW_STAFF) + DOUBLE_DELETE;
		throw std::exception(res.c_str());
	}
	return *staff_in_this_blank;
}

Call_Info Blank::do_damage_to_me(Damage damage)
{
	return staff_in_this_blank->do_damage(damage);
}

Blank_Call_Info Blank::normal_call()
{
	return Blank_Call_Info();
}

Blank_Call_Info Blank::normal_attack(Damage damage)
{
	return sys_ptr->try_attack(this,damage).get_Info();
}
