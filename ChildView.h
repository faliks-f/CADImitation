#include <vector>
#include "GetCircleDataDialog.h"
// ChildView.h: CChildView 类的接口
//


#pragma once

using Circle = struct Circle
{
	int x;
	int y;
	int r;
};

using Line = struct Line
{
	CPoint start;
	CPoint end;
};

// CChildView 窗口

class CChildView : public CWnd
{
private:
	bool needClear = false;
	CPoint currentPoint;
	CPoint lastPoint;
	std::vector<Circle> circles;
	std::vector<Line> lines;
	void drawCoordinate(CClientDC &dc);
	void drawExistLine(CClientDC &dc);
	void drawCurrentLine(CClientDC &dc);

// 构造
public:
	CChildView();
	void drawCircle(CClientDC& dc);
	void clearLine();
	void clearCircle();
	void clearAll();

// 特性
public:

// 操作
public:
	void addCircle(int x, int y, int r);
	void addLine(CPoint start, CPoint end);
// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
	void OnDraw();
	
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
