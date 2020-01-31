//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include<vector>
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


class Event {
public:
	virtual void event_exc() {
		std::cout << "Please implement Event::event_exc()\n";
		return;
	}
};

class Staff {
public:
	Staff() = default;
};