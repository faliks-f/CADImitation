#pragma once
#include "string"

class Utils
{
public:
	static std::string cstring2String(CString& str);
	static CString string2CString(std::string& str);
	static int string2Int(std::string& str);
	static std::string int2String(int data);
};


