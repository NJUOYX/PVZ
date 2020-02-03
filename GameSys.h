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
};

class GameSys:public Blank_Sys_Call{
public:
	GameSys(GameLoader const&loader);
	int exc();//��ʱ����
	void add_event(Event* _event);
	//POS ��صĳ�����pch.h��
	int fill_staff_in_blank(Pos const& position, Staff* new_staff);
	int del_staff_in_blank(Pos const& position);
	Staff const& view_staff(Pos const&position);
public://blank
	Call_Info normal_sys_call()override;
private:
	bool pos_check(Pos const& position)const;
private:
	std::vector<Event*>event_ptrs;
};