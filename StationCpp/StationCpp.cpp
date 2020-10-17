// StationCpp.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
#include "StationCpp.h"

#using "WindowsBase.dll"
#using "PresentationCore.dll"
#using "PresentationFramework.dll"
#using "../Station/bin/Release/Station.dll"

using namespace Station;

extern "C" STATIONCPP_API bool GetPos(double* pos)
{
	//Dialog ^dialog = gcnew Dialog();
	//StationModel ^station = dialog->GetStation();
	StationModel ^station = StationDialog::GetStation();
	if (station == nullptr) return false;
	pos[0] = station->Longitude;
	pos[1] = station->Latitude;
	return true;
}
