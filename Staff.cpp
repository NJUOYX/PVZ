#include "pch.h"
#include "Staff.h"

One_Shot_Plant::One_Shot_Plant():attribute()
{
}

Staff_Info One_Shot_Plant::exc(Blank_Call*e_ptr)
{
	Blank_Call* blank_call(e_ptr);
	blank_call->normal_attack(attribute.do_damage());
	return Staff_Info(1);
}

Staff_Info One_Shot_Plant::do_damage(int damage)
{
	attribute.damage_me(damage);
	return Staff_Info(1);
}

bool One_Shot_Plant::is_alive() const
{
	return attribute.is_alive();
}
