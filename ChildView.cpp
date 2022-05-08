
// ChildView.cpp: CChildView 类的实现
//

#include "pch.h"
#include "framework.h"
#include "CADImitation.h"
#include "ChildView.h"
#include "Utils.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView



CChildView::CChildView()
{
	lastPoint = CPoint(-1, -1);

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
//	ON_WM_TIMER()
ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView 消息处理程序


BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this);
	// TODO: 在此处添加消息处理程序代码
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnLButtonDown(UINT, CPoint point)
{
	//MessageBox(TEXT("hello"));
	if (lastPoint.x < 0 || lastPoint.y < 0)
	{
		lastPoint = point;
		needClear = true;
		SetTimer(1, 80, nullptr);
	} 
	else
	{
		CPoint temp = lastPoint;
		currentPoint = point;
		lastPoint = CPoint(-1, -1);
		addLine(temp, currentPoint);
		OnDraw();
		needClear = false;
	}
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	this->currentPoint = point;
	//UpdateWindow();
}



void CChildView::addLine(CPoint start, CPoint end)
{
	Line line;
	line.start = start;
	line.end = end;
	lines.push_back(line);
}

void CChildView::addCircle(int x, int y, int r)
{
	Circle circle;
	circle.x = x;
	circle.y = y;
	circle.r = r;
	circles.push_back(circle);
}

void CChildView::OnDraw()
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 6, RGB(0, 0, 0));
	CBrush brush(RGB(255, 255, 255));
	CRect rect;
	GetClientRect(&rect);
	if (needClear)
	{
		dc.FillRect(&rect, &brush);
	}
	dc.SelectObject(pen);
	drawCurrentLine(dc);
	drawCircle(dc);
	drawCoordinate(dc);
	drawExistLine(dc);
}

void CChildView::drawCircle(CClientDC& dc)
{
	for (auto c : circles)
	{
		int x = c.x;
		int y = c.y;
		int r = c.r;
		dc.Ellipse(x - r / 2, y - r / 2, x + r / 2, y + r / 2);
	}
}

void CChildView::clearLine()
{
	lines.clear();
	OnDraw();
}

void CChildView::clearCircle()
{
	circles.clear();
	OnDraw();
}

void CChildView::clearAll()
{
	clearLine();
	clearCircle();
}

void CChildView::drawCoordinate(CClientDC& dc)
{
	string s = "(" + Utils::int2String(currentPoint.x) + ", " + Utils::int2String(currentPoint.y) + ")";
	int length = s.length();
	for (int i = 0; i < 20 - length; ++i)
	{
		s += "  ";
	}
	CRect rt;
	GetClientRect(&rt);
	CString output = Utils::string2CString(s);
	CRect pos(10, rt.Height() - 30, 210, rt.Height());
	dc.DrawText(output, pos, DT_SINGLELINE);
}

void CChildView::drawExistLine(CClientDC& dc)
{
	for (auto line : lines)
	{
		dc.MoveTo(line.start);
		dc.LineTo(line.end);
	}
}

void CChildView::drawCurrentLine(CClientDC& dc)
{
	if (lastPoint.x >= 0 && lastPoint.y >= 0)
	{
		dc.MoveTo(lastPoint);
		dc.LineTo(currentPoint);
	}
}


//void CChildView::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	OnDraw();
//	CWnd::OnTimer(nIDEvent);
//}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	OnDraw();
	CWnd::OnTimer(nIDEvent);
}
