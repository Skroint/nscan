#pragma once
#include <vector>
#include <string>
#include "scan_result.h"
#include "ipv4_address.h"
#include "device_address.h"

class host_scanner
{
public:

	virtual void scan(scan_result* sr, 
		const std::vector<ipv4_address>& addresses, 
		const device_address da) = 0;

};

