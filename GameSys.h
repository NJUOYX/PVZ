#pragma once
#include"pch.h"

class GameLoader {
public:
	GameLoader();
	~GameLoader();
	virtual std::vector<Event*>get_event_ptrs()const;
private:
	std::vector<Event*>ptrs;
};

struct Pos {
	int row;
	int col;
	Pos():row(0),col(0){}
	Pos(int row,int col):row(row),col(col){}
};

class GameSys{
public:
	GameSys(GameLoader const&loader);
	int exc();//暂时不用
	void add_event(Event* _event);
	//POS 相关的常数在pch.h中
	int fill_staff_in_blank(Pos const& position, Staff* new_staff);
	int del_staff_in_blank(Pos const& position);
	Staff const& view_staff(Pos const&position);
private:
	std::vector<Event*>event_ptrs;
};

