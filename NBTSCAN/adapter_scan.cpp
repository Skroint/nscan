//#include "adapter_scan.h"
//
//int adapter_count = 0;
//
//std::vector<adapter*> scan_adapters()
//{
//	// Create file with adapters
//	system("ipconfig > ip.txt");
//	
//	// Open file
//	std::ifstream file;
//	file.open("ip.txt");
//
//	// Loop through file
//	std::string line;
//	std::string last_line;
//	std::vector<adapter*> adapters;
//	while (file.is_open() && !file.eof())
//	{
//		last_line = line;
//		std::getline(file, line);
//		adapter* ad = scan_adapter_file_line(line, last_line);
//		if (ad != NULL)
//			adapters.push_back(ad);
//	}
//
//	return adapters;
//}
//
//adapter* scan_adapter_file_line(std::string line, std::string last_line)
//{
//	std::string line_temp = line;
//	std::string last_line_temp = last_line;
//
//	std::string ip_search = "IPv4 Address";
//	std::string netmask_search = "Subnet Mask";
//
//	int ip_offset = last_line_temp.find(ip_search);
//	int netmask_offset = line_temp.find(netmask_search);
//
//	if (ip_offset == std::string::npos) return NULL;
//	if (netmask_offset == std::string::npos) return NULL;
//
//	line_temp = line_temp.erase(0, 39);
//	last_line_temp = last_line_temp.erase(0, 39);
//
//	return new adapter(last_line_temp, line_temp, adapter_count++);
//}
