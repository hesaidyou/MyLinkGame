#pragma once
#include"stdafx.h"

class Player
{
public:
	Player(char* name, double time);
	char* Get_Name() const;
	double Get_Time() const;
	void point(char* Name, double Time);
	void Game_End(CString qname, double now_time);
	~Player();
	void set_name(char* Name);
	void set_time(double Time);
	CString qname;
private:
	char* name;
	double time;
};






