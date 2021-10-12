#pragma once
#pragma comment(lib, "setupapi.lib")
#include<Windows.h>
#include<iostream>
#include<SetupAPI.h>
#include<string>

class PCI_Device
{
private:
	HDEVINFO deviceInfo;
	SP_DEVINFO_DATA deviceData;
public:
	PCI_Device();

	bool bind(DWORD index);
	std::wstring getName();
	std::wstring getVendorID();
	std::wstring getDeviceID();

	~PCI_Device();
};