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

class GameSys;
GameSys* sys_ptr;
class Event;
class Blank_Call;
class Blank_Sys_Call;
using Staff_Info = int;
class Staff {
public:
	virtual Staff_Info exc(Blank_Call*e_ptr) = 0;
	virtual Staff_Info do_damage(int damage) = 0;
	virtual bool is_alive()const = 0;
};

class Event {
public:
	virtual void event_exc() = 0;

	virtual int fill_staff(Staff* staff) = 0;

	virtual int del_staff() = 0;

	virtual Staff const& view_staff()const = 0;
};

class STAFF_ATTR
{
private:
	int hp;
	int damage;
public:
	STAFF_ATTR() :hp(0), damage(0) {}
	STAFF_ATTR(int hp, int damage) :hp(hp), damage(damage) {}
	int do_damage() {
		return damage;
	}
	int show_hp()const {
		return hp;
	}
	int damage_me(int damage) {
		hp -= damage;
		return hp;
	}
	bool is_alive()const {
		return hp > 0;
	}
};
