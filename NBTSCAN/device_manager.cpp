#include "device_manager.h"
#include <string>
#include <iostream>
#include <iphlpapi.h>
#include <sstream>
#include <iomanip>
#include "console_tools.h"


device_manager::device_manager()
{
	load_devices();
}


void device_manager::load_devices()
{
	std::vector<device_address> addresses;

	IP_ADAPTER_INFO* adapter = nullptr;
	ULONG ulOutBufLen = 0;

	if (GetAdaptersInfo(adapter, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		free(adapter);
		adapter = (PIP_ADAPTER_INFO)malloc(ulOutBufLen);
	}
	GetAdaptersInfo(adapter, &ulOutBufLen);

	while (adapter)
	{
		IP_ADDR_STRING* adapter_address = &adapter->IpAddressList;
	
		while (adapter_address)
		{
			device_address dev_address;

			dev_address.device_name = adapter->AdapterName;
			dev_address.device_description = adapter->Description;
			dev_address.mac = mac_address::from_octets(adapter->Address);
		
			std::string tesst = std::string(adapter_address->IpAddress.String);
			dev_address.ip = ipv4_address::from_string(tesst);
			dev_address.mask = ipv4_address::from_string(std::string(adapter_address->IpAddress.String));
			
			adapter_address = adapter_address->Next;
			addresses.push_back(dev_address);
		}


		adapter = adapter->Next;



		all_addresses = addresses;
	}


}



device_manager::~device_manager()
{

}

void device_manager::print_all_addresses()
{
	console_tools ct(true);

	int index = 0;
	for (auto address : all_addresses)
	{
		ct.write("[" + std::to_string(index) + "] ", console_color::dark_yellow);
		ct.write(address.device_name + " ", console_color::bright_grey);
		ct.write(address.device_description + " ", console_color::bright_grey);
		std::cout << std::endl;
		/*ct.write("[" + address.ip.to_string() + "] ", console_color::white);
		ct.write(" : [" + address.mask.to_string() + "] ", console_color::bright_grey);
		ct.write("[" + address.mac.to_string() + "] ", console_color::bright_grey);*/

		ct.write_property("MAC", address.mac.to_string());
		ct.write_property("IP", address.ip.to_string());
		ct.write_property("MASK", address.mask.to_string());
		
	//	ct.write(address.device_name + " ", console_color::bright_grey);
	//	ct.write(address.device_name + " ", console_color::bright_grey);

		std::cout << std::endl;
		index++;
	}
}






