// StationTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

//���庯��ָ�����ͺͺ���ָ��
typedef bool(__cdecl *pGetPos)(double*);
pGetPos GetPos;

//��ʼ�����������ڻ�ȡ����ָ��
void Init()
{
	HINSTANCE hDll = LoadLibrary(L"StationCpp.dll");
	GetPos = (pGetPos)GetProcAddress(hDll, "GetPos");
}

int main()
{
	Init();
	double pos[2] = {0};
	
	//����GetPosǰ����øú���������STAThreadִ��GetPos
	CoInitialize(NULL);
	if (GetPos(pos))
	{
		std::cout << "���ȣ�" << pos[0] << std::endl;
		std::cout << "γ�ȣ�" << pos[1] << std::endl;
	}

	getchar();

	return 0;
}



