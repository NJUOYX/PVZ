//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<vector>
#include<string>
#include<list>
#include<iostream>
#include<queue>
#include<algorithm>
#include"Info.h"
#ifdef TEST
#define private public
#define protected public
#define ASSERT {throw "please implement it\n";}
#endif

#define ONE_ROW_GAME
#define MUL_ROW_GAME

constexpr auto ROW_INDEX_MIN = 0;
constexpr auto COL_INDEX_MAX = 5;
constexpr auto COL_INDEX_MIN = 0;
constexpr auto COL_MAX = 6;
#ifdef ONE_ROW_GAME
constexpr auto ROW_INDEX_MAX = 0;
constexpr auto ROW_MAX = 1;
#elif MUL_ROW_GAME
constexpr auto ROW_INDEX_MAX = 8;
constexpr auto ROW_MAX = 9;
#endif

constexpr auto INT_RETURN_TRUE = 0;
constexpr auto INT_RETURN_FALSE = -1;


class Event;
class Blank_Call;
class Blank_Sys_Call;


class Staff_Info :public Info{
public:
	Staff_Info() :Info(){}
	Staff_Info(int info):Info(info){}
};



class Call_Info;



class Damage {
public:
	Damage() :damage(0) {}
	Damage(int damage) :damage(damage) {}
	int get_int_damage()const {
		return damage;
	}
private:
	int damage;
};

class Health {
public:
	Health():hp(0){}
	Health(int hp):hp(hp){}
	Health& normal_decline(Damage damage) {
		hp -= damage.get_int_damage();
		return *this;
	}
	bool is_alive()const {
		return hp > 0;
	}
	int get_hp()const {
		return hp;
	}
private:
	int hp;
};

class STAFF_ATTR
{
private:
	Health hp;
	Damage damage;
public:
	STAFF_ATTR() :hp(0), damage(0) {}
	STAFF_ATTR(Health hp, Damage damage) :hp(hp), damage(damage) {}
	Damage do_damage() {
		return damage;
	}
	Health show_hp()const {
		return hp;
	}
	Health damage_me(Damage damage) {
		hp.normal_decline(damage);
		return hp;
	}
	bool is_alive()const {
		return hp.is_alive();
	}
};

class Staff {
public:
	virtual Staff_Info exc(Blank_Call* e_ptr) = 0;
	virtual Staff_Info do_damage(Damage damage) = 0;
	virtual bool is_alive()const = 0;
};

class Event {
public:
	virtual void event_exc() = 0;

	virtual int fill_staff(Staff* staff) = 0;

	virtual int del_staff() = 0;

	virtual Staff const& view_staff()const = 0;

	virtual Call_Info do_damage_to_me(Damage damage) = 0;

	virtual void load_sys(Blank_Sys_Call* sys_ptr) = 0;
};

