// StationTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

//定义函数指针类型和函数指针
typedef bool(__cdecl *pGetPos)(double*);
pGetPos GetPos;

//初始化函数，用于获取函数指针
void Init()
{
	HINSTANCE hDll = LoadLibrary(L"StationCpp.dll");
	GetPos = (pGetPos)GetProcAddress(hDll, "GetPos");
}

int main()
{
	Init();
	double pos[2] = {0};
	
	//调用GetPos前需调用该函数，用于STAThread执行GetPos
	CoInitialize(NULL);
	if (GetPos(pos))
	{
		std::cout << "经度：" << pos[0] << std::endl;
		std::cout << "纬度：" << pos[1] << std::endl;
	}

	getchar();

	return 0;
}



