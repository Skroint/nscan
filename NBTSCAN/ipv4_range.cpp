#include "ipv4_range.h"
#include <iostream>

ipv4_range::ipv4_range(ipv4_address from, ipv4_address to)
{
    this->from = from;
    this->to = to;
}

ipv4_range::ipv4_range()
{
    this->from = ipv4_address();
    this->to = ipv4_address();
}

std::vector<ipv4_address> ipv4_range::get_addresses()
{
    std::vector<ipv4_address> addresses;
    ipv4_address address;
    
    for (int a = from.octets[0]; a < to.octets[0]; a++)
    {
        for (int b = from.octets[0]; b < to.octets[0]; b++)
        {
            for (int c = from.octets[0]; c < to.octets[0]; c++)
            {
                for (int d = from.octets[0]; d < to.octets[0]; d++)
                {
                    address.octets[0] = a;
                    address.octets[1] = b;
                    address.octets[2] = c;
                    address.octets[3] = d;
                    addresses.push_back(address);
                }
            }
        }
    }

    return addresses;
}

void ipv4_range::print()
{
    std::cout << from.to_string() << " - " << to.to_string();
}
