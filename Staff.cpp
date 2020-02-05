#include "pch.h"
#include "Staff.h"

One_Shot_Plant::One_Shot_Plant():attribute()
{
}

One_Shot_Plant::One_Shot_Plant(STAFF_ATTR attr):attribute(attr)
{
}

Staff_Info One_Shot_Plant::exc(Blank_Call*e_ptr)
{
	Blank_Call* blank_call(e_ptr);
	blank_call->normal_attack(attribute.do_damage());
	return Staff_Info(1);
}

Staff_Info One_Shot_Plant::do_damage(Damage damage)
{
	attribute.damage_me(damage);
	return Staff_Info(1);
}

bool One_Shot_Plant::is_alive() const
{
	return attribute.is_alive();
}

Normal_Zombie::Normal_Zombie()
{
}

Normal_Zombie::Normal_Zombie(STAFF_ATTR attr):attribute(attr)
{
}

Staff_Info Normal_Zombie::exc(Blank_Call* e_ptr)
{
	auto require_info = e_ptr->zb_move_require();
	if(require_info.is_permit())
		return Staff_Info(1);
	else {
		return Staff_Info(0);
	}
}

Staff_Info Normal_Zombie::do_damage(Damage damage)
{
	return Staff_Info(attribute.damage_me(damage).get_hp());
}

bool Normal_Zombie::is_alive() const
{
	return attribute.is_alive();
}
