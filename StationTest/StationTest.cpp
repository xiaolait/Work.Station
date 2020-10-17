// StationTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

typedef bool(__cdecl *pGetPos)(double*);
pGetPos GetPos;


void Init()
{
	HINSTANCE hDll = LoadLibrary(L"StationCpp.dll");
	std::cout << "hDll：" << hDll << std::endl;
	GetPos = (pGetPos)GetProcAddress(hDll, "GetPos");
	std::cout << "GetPos：" << (int)GetPos << std::endl;
}

int main()
{
	Init();
	double pos[2] = {0};
	
	CoInitialize(NULL);
	if (GetPos(pos))
	{
		std::cout << "经度：" << pos[0] << std::endl;
		std::cout << "纬度：" << pos[1] << std::endl;
	}

	getchar();

	return 0;
}



