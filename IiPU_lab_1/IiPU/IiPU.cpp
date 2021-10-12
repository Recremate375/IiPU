#include <iostream>
#include "PCIDevice.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	PCI_Device source;
	DWORD i = 0;
	while (source.bind(i++))
	{
		std::cout << std::endl;
		std::cout << "Device #" << i << ":" << std::endl;
		std::wcout << "name: " << source.getName() << std::endl;
		std::wcout << "DeviceID: " << source.getDeviceID() << std::endl;
		std::wcout << "VendorID: " << source.getVendorID() << std::endl;
	}
	system("pause");
	return 0;
}


