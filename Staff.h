#pragma once
#include"pch.h"

using Blank_Call_Info = int;

class Blank_Call {
public:
	virtual Blank_Call_Info normal_call() = 0;
	virtual Blank_Call_Info normal_attack(int damage) = 0;
};

class One_Shot_Plant :public Staff{
public:
	One_Shot_Plant();
	Staff_Info exc(Blank_Call*e_ptr)override;
	Staff_Info do_damage(int damage)override;
	bool is_alive()const override;
private:
	STAFF_ATTR attribute;
};


class Normal_Zombie :public Staff{
public:
	Normal_Zombie();
	Staff_Info exc(Blank_Call* e_ptr)override;
};