#pragma once
#include "afxcmn.h"
class MyProgress :
	public CProgressCtrl
{
public:
	MyProgress();
	~MyProgress();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

