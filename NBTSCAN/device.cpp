#include "device.h"


device::device(pcap_if_t* ptr)
{
	this->dev_ptr = ptr;
}
