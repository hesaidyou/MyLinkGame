#pragma once
#include"stdafx.h"
#include <iostream>  
#include <fstream>  
using namespace std;

/*
	创建一个子窗体

	窗体之间的调用还未清楚
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