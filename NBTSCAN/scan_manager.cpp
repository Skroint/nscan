#include "scan_manager.h"


scan_manager::scan_manager()
{
	scanners.push_back(arp_host_scanner());
}

scan_result scan_manager::scan(device_address da)
{
	ipv4_range range = da.get_range();
	std::vector<ipv4_address> addresses = range.get_addresses();
	scan_result sr = scan_result::initialize(addresses.size());

	for (auto& scanner : scanners)
	{
		scanner.scan(&sr, addresses, da);
	}

	return scan_result();
}
