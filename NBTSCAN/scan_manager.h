#pragma once
#include <vector>
#include "host_scanner.h"
#include "arp_host_scanner.h"
#include "scan_result.h"
#include "device_address.h"


class scan_manager
{
public:
	scan_manager();
	scan_result scan(device_address da);


private:
	std::vector<host_scanner> scanners;
};

