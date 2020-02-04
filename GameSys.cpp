#include "pch.h"
#include "GameSys.h"


GameSys::GameSys(GameLoader const&loader)
{
	this->event_ptrs = loader.get_event_ptrs();
	for (auto& i : event_ptrs)
		i->load_sys(this);
}

int GameSys::exc()
{
	for (auto i : event_ptrs)
		i->event_exc();
	return 0;
}

void GameSys::add_event(Event* _event)
{
	event_ptrs.push_back(_event);
}

int GameSys::fill_staff_in_blank(Pos const& position, Staff* new_staff)
{
#ifdef ONE_ROW_GAME
	if (pos_check(position))
	{
		return find_pos_event(position)->fill_staff(new_staff);
	}
	else
		return INT_RETURN_FALSE;
#elif MUL_ROW_GAME

#endif
	return INT_RETURN_FALSE;
}

int GameSys::del_staff_in_blank(Pos const& position)
{
#ifdef ONE_ROW_GAME
	if (pos_check(position))
	{
		return find_pos_event(position)->del_staff();
}
	else
		return INT_RETURN_FALSE;
#elif MUL_ROW_GAME

#endif
	return INT_RETURN_FALSE;
}

Staff const& GameSys::view_staff(Pos const& position)const
{
	if (pos_check(position))
	{
		return find_pos_event(position)->view_staff();
	}
	else
		return *new Standard();
}

Event const& GameSys::view_event(Pos const& position) const
{
	if (pos_check(position))
		return *find_pos_event(position);
	else
		return *new Blank();
}

Call_Info GameSys::normal_sys_call()
{
	return Call_Info(1);
}

Call_Info GameSys::try_attack(Event* sender, Damage damage)
{
	auto pos_sender = find_event_pos(sender);
	if (pos_check(pos_sender))
	{
		auto pos_receiver = next_pos(pos_sender);
		if (pos_check(pos_receiver))
		{
			auto receiver = find_pos_event(pos_receiver);
			return receiver->do_damage_to_me(damage);
		}
	}
	return Call_Info(INT_RETURN_FALSE);
}

bool GameSys::pos_check(Pos const& position) const
{
	if (position.col<COL_INDEX_MIN || position.col>COL_INDEX_MAX)
		return false;
	else if (position.row<ROW_INDEX_MIN || position.row>ROW_INDEX_MAX)
		return false;
	else
		return true;
}

Pos GameSys::find_event_pos(Event* e_ptr) const
{
#ifdef ONE_ROW_GAME
	int x = 0;
	for (auto i : event_ptrs)
		if (e_ptr == i)
			return { ROW_INDEX_MIN,x };
		else
			x++;
	return { ROW_INDEX_MIN, x };
#endif
}

Pos GameSys::next_pos(Pos pos) const
{
	return pos.add_col(1);
}

Event* GameSys::find_pos_event(Pos pos) const
{
	return event_ptrs[pos.col];
}

GameLoader::GameLoader():ptrs(COL_MAX)
{
	for (auto& i : ptrs)
		i = new Blank();
}

GameLoader::~GameLoader()
{
	for (auto& i : ptrs)
		delete i;
}

std::vector<Event*> GameLoader::get_event_ptrs()const
{
	return ptrs;
}
