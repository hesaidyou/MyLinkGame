#include "stdafx.h"
#include "MyProgress.h"


MyProgress::MyProgress()
{
}


MyProgress::~MyProgress()
{
}


BEGIN_MESSAGE_MAP(MyProgress, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void MyProgress::OnPaint()
{
	CPaintDC dc(this);
	CBrush BackgroundBrush;
	BackgroundBrush.CreateSolidBrush(RGB(255, 0, 0));
	CBrush ForeBrush;
	ForeBrush.CreateSolidBrush(RGB(100, 255, 0));
	CRect r;
	this->GetClientRect(r);

	double With = r.Width();

	int min, max;
	this->GetRange(min, max);

	int pos = this->GetPos();
	double unit = (double)r.Height() / (max - min);

	dc.FillRect(r, &BackgroundBrush);

	r.top = (max-pos)*unit;
	
	dc.FillRect(r, &ForeBrush);
}
