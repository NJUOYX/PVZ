#include "pch.h"
#include "GameSys.h"


GameSys::GameSys(GameLoader const&loader)
{
	this->event_ptrs = loader.get_event_ptrs();
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
		return event_ptrs[position.col]->fill_staff(new_staff);
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
		return event_ptrs[position.col]->del_staff();
}
	else
		return INT_RETURN_FALSE;
#elif MUL_ROW_GAME

#endif
	return INT_RETURN_FALSE;
}

Staff const& GameSys::view_staff(Pos const& position)
{
	if (pos_check(position))
	{
		return event_ptrs[position.col]->view_staff();
	}
	else
		return Staff();
}

Call_Info GameSys::normal_sys_call()
{
	return Call_Info(1);
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
