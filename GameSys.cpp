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
	ASSERT;
	return 0;
}

int GameSys::del_staff_in_blank(Pos const& position)
{
	ASSERT;
	return 0;
}

Staff const& GameSys::view_staff(Pos const& position)
{
	// TODO: 返回一个Staff对象，当时调用者不能对获得的Staff对象进行修改
	ASSERT;
}

GameLoader::GameLoader():ptrs(COL_MAX)
{
	for (auto& i : ptrs)
		i = new Event();
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
