#pragma once
#include"stdafx.h"
#include <iostream>  
#include <fstream>  
using namespace std;

/*
	����һ���Ӵ���

	����֮��ĵ��û�δ���
*/


class Rank
{

public:
	Rank();




private:
	char* name[5];
	int time[5];
	char *Name = (char*)malloc(10 * sizeof(char));
	int Time;
	int rank = 0;




};