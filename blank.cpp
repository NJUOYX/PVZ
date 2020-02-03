#include "pch.h"
#include "blank.h"

Blank::Blank():staff_in_this_blank(nullptr)
{
}

Blank::~Blank()
{
	if (staff_in_this_blank != nullptr)
		delete staff_in_this_blank;
}

void Blank::event_exc()
{
	std::cout << "implement blank event_exc()\n";
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
