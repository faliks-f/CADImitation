#pragma once
#include <afxdialogex.h>
#include "resource.h"
#include <string>

class GetCircleDataDialog :
    public CDialog
{
	
private:
	std::string x;
	std::string y;
	std::string radius;

public:
	GetCircleDataDialog(CWnd *pParent = nullptr);
	virtual ~GetCircleDataDialog();
	enum { IDD = IDD_GET_CIRCLE_DATA };

	std::string getX() const;
	void setX(CString& x);
	std::string getY() const;
	void setY(CString& y);
	std::string getRadius() const;
	void setRadius(CString& radius);
	

protected:
	virtual void DoDataExchange(CDataExchange *pDX);
	void OnOk();
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void saveWhenClose();
	
	afx_msg void OnBnClickedOk();
};

