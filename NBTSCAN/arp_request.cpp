//#include "arp_request.h"
//
//int arp_request(target* target)
//{
//	DWORD dwRetVal;
//	IPAddr DestIp = 0;
//	IPAddr SrcIp = 0;
//	ULONG MacAddr[2];
//	ULONG PhysAddrLen = 6;
//
//	BYTE *bPhysAddr;
//	unsigned int i;
//
//	InetPton(AF_INET, target->ip.c_str(), &DestIp);
//	InetPton(AF_INET, target->adapter_ip.c_str(), &SrcIp);
//	
//	memset(&MacAddr, 0xff, sizeof(MacAddr));
//
//	if (SendARP(DestIp, SrcIp, &MacAddr, &PhysAddrLen) == NO_ERROR)
//	{
//		bPhysAddr = (BYTE*)&MacAddr;
//		if (PhysAddrLen) 
//		{
//			target->found = true;
//			
//			std::stringstream stream;
//			for (i = 0; i < (int)PhysAddrLen; i++)
//			{
//				stream << std::hex 
//					   << std::setw(2)
//					   << std::setfill('0')
//					   << (int)bPhysAddr[i];
//				
//				if (i < PhysAddrLen - 1) stream << ":";
//			}
//			target->mac = stream.str();
//		}
//	}
//	else
//	{
//	// Not found
//	}
//
//	
//
//
//	return 0;
//}