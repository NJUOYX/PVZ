#pragma once
#include"pch.h"

class Blank_Call_Info :public Info{
public:
	Blank_Call_Info() :Info(){}
	Blank_Call_Info(Info info):Info(info){}
	Info get_Info()const { return info; }
};

class Blank_Call {
public:
	virtual Blank_Call_Info normal_call() = 0;
	virtual Blank_Call_Info normal_attack(Damage damage) = 0;
};

class Standard :public Staff {
public:
	Standard() = default;
	Staff_Info exc(Blank_Call* e_ptr)override {
		return Staff_Info();
	}
	Staff_Info do_damage(Damage damage)override {
		return Staff_Info();
	}
	bool is_alive()const override {
		return false;
	}
};

class One_Shot_Plant :public Staff{
public:
	One_Shot_Plant();
	One_Shot_Plant(STAFF_ATTR attr);
	Staff_Info exc(Blank_Call*e_ptr)override;
	Staff_Info do_damage(Damage damage)override;
	bool is_alive()const override;
private:
	STAFF_ATTR attribute;
};


class Normal_Zombie :public Staff{
public:
	Normal_Zombie();
	Normal_Zombie(STAFF_ATTR attr);
	Staff_Info exc(Blank_Call* e_ptr)override;
	Staff_Info do_damage(Damage damage)override;
	bool is_alive()const override;
private:
	STAFF_ATTR attribute;
};