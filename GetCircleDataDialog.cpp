#include "pch.h"
#include "GetCircleDataDialog.h"
#include "Utils.h"

using namespace std;

GetCircleDataDialog::GetCircleDataDialog(CWnd* pParent) : CDialog(GetCircleDataDialog::IDD, pParent)
{
 
	
} 

GetCircleDataDialog::~GetCircleDataDialog()
{
}

void GetCircleDataDialog::DoDataExchange(CDataExchange* pDX)
{
}

void GetCircleDataDialog::OnOk()
{
	
}

void GetCircleDataDialog::saveWhenClose()
{
	
}

BEGIN_MESSAGE_MAP(GetCircleDataDialog, CDialog)
	ON_BN_CLICKED(IDOK, &GetCircleDataDialog::OnBnClickedOk)
END_MESSAGE_MAP()





string GetCircleDataDialog::getX() const
{
	return x;
}

void GetCircleDataDialog::setX(CString& x)
{
	this->x = Utils::cstring2String(x);
}

string GetCircleDataDialog::getY() const
{
	return y;
}

void GetCircleDataDialog::setY(CString& y)
{
	this->y = Utils::cstring2String(y);
}

string GetCircleDataDialog::getRadius() const
{
	return radius;
}
void GetCircleDataDialog::setRadius(CString& radius)
{
	this->radius = Utils::cstring2String(radius);
}


void GetCircleDataDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	CString tempX, tempY, tempR;
	((CEdit*)GetDlgItem(GET_X))->GetWindowTextW(tempX);
	((CEdit*)GetDlgItem(GET_Y))->GetWindowTextW(tempY);
	((CEdit*)GetDlgItem(GET_RADIUS))->GetWindowTextW(tempR);
	setX(tempX);
	setY(tempY);
	setRadius(tempR);
}
