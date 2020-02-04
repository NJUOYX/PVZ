#pragma once

class Info {
public:
	Info():info(0){}
	Info(int info) :info(info) {}
	bool operator ==(int val) {
		return info == val;
	}
protected:
	int info;
};