#include "ipv4_address.h"

ipv4_address ipv4_address::from_octets(uint8_t* src)
{
    ipv4_address address;

    memcpy(&address.octets, src, 4 * sizeof(uint8_t));
    
    return address;
}

std::string ipv4_address::to_string()
{
    return std::to_string(this->octets[0]) + "." +
        std::to_string(this->octets[1]) + "." +
        std::to_string(this->octets[2]) + "." +
        std::to_string(this->octets[3]);
}
