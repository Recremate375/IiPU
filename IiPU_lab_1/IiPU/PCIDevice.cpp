#include "PCIDevice.h"

PCI_Device::PCI_Device()
{
	this->deviceInfo = SetupDiGetClassDevs(nullptr, TEXT("PCI"), nullptr, DIGCF_PRESENT | DIGCF_ALLCLASSES);
}

bool PCI_Device::bind(DWORD index)
{
	deviceData.cbSize = sizeof(SP_DEVINFO_DATA);
	return SetupDiEnumDeviceInfo(deviceInfo, index, &deviceData);
}

std::wstring PCI_Device::getName()
{
	TCHAR buffer[1024];
	SetupDiGetDeviceRegistryPropertyW(deviceInfo, &deviceData, SPDRP_DEVICEDESC, nullptr, (BYTE*)buffer, 1024, nullptr);
	return std::wstring{ buffer };
}

std::wstring PCI_Device::getVendorID()
{
	TCHAR buffer[1024];
	SetupDiGetDeviceRegistryPropertyW(deviceInfo, &deviceData, SPDRP_HARDWAREID, nullptr, (BYTE*)buffer, 1024, nullptr);
	return std::wstring{ buffer }.substr(std::wstring{ buffer }.find(L"DEV_") + 4, 4);
}

std::wstring PCI_Device::getDeviceID()
{
	TCHAR buffer[1024];
	SetupDiGetDeviceRegistryPropertyW(deviceInfo, &deviceData, SPDRP_HARDWAREID, nullptr, (BYTE*)buffer, 1024, nullptr);
	return std::wstring{ buffer }.substr(std::wstring{ buffer }.find(L"VEN_") + 4, 4);
}

PCI_Device::~PCI_Device()
{
	SetupDiDestroyDeviceInfoList(deviceInfo);
}
