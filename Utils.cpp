#include "pch.h"
#include "Utils.h"

using namespace std;

string Utils::cstring2String(CString& str)
{
    string res;
    res = CT2A(str.GetString());
    return res;
}

CString Utils::string2CString(string& str)
{
    CString res;
    res = CA2T(str.c_str());
    return res;
}


int Utils::string2Int(string& str)
{
    int res = 0;
    if (!str.length())
    {
        throw exception("请输入数字!");
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw exception("请输入合法的数字!");
        }
        res *= 10;
        res += str[i] - '0';
    }
    return res;
}

string Utils::int2String(int data)
{
    string res = "";
    if (data == 0)
    {
        return "0";
    }
    while (data)
    {
        res.insert(res.begin(), data % 10 + '0');
        data /= 10;
    }
    return res;
}
