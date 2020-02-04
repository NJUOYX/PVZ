#pragma once
#include"pch.h"
#include"blank.h"
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
	Pos& add_col(int dis) { col += dis; return *this; }
};

class GameSys:public Blank_Sys_Call{
public:
	GameSys(GameLoader const&loader);
	int exc();//暂时不用
	void add_event(Event* _event);
	//POS 相关的常数在pch.h中
	int fill_staff_in_blank(Pos const& position, Staff* new_staff);
	int del_staff_in_blank(Pos const& position);
	Staff const& view_staff(Pos const& position)const;
	Event const& view_event(Pos const& position)const;
public://blank
	Call_Info normal_sys_call()override;
	Call_Info try_attack(Event* sender, Damage damage)override;
private:
	bool pos_check(Pos const& position)const;
	Pos find_event_pos(Event* e_ptr)const;
	Pos next_pos(Pos pos)const;
	Event* find_pos_event(Pos pos)const;
private:
	std::vector<Event*>event_ptrs;
};