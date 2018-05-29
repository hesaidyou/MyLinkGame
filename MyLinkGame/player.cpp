#include "player.h"

Player::Player(char * name, double time)
{
	(*this).name = name;
	(*this).time = time;
}

char * Player::Get_Name() const
{
	return name;
}

double Player::Get_Time() const
{
	return time;
}

void Player::point(char * Name, double Time)
{




}

void Player::Game_End(CString qname, double now_time)
{
}

Player::~Player()
{
}

void Player::set_name(char * Name)
{
}

void Player::set_time(double Time)
{
}
