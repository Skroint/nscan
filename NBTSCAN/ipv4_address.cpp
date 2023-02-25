#include "ipv4_address.h"
#include <ctype.h>

ipv4_address ipv4_address::from_octets(uint8_t* src)
{
    ipv4_address address;

    memcpy(&address.octets, src, 4 * sizeof(uint8_t));
    
    return address;
}

ipv4_address ipv4_address::from_string(std::string str)
{
    ipv4_address address;

    int octet_index = 0;
    std::string part = "";
    for (char& c : str)
    {
        if (c == '.')
        {
            address.octets[octet_index] = (unsigned char)std::stoi(part);
            octet_index++;
            part = "";
        }
        else if (isdigit(c))
        {
            part += c;
        }
        else
        {
            throw std::exception("Invalid character");
        }
    }

    return address;
}

std::string ipv4_address::to_string()
{
    return std::to_string(this->octets[0]) + "." +
        std::to_string(this->octets[1]) + "." +
        std::to_string(this->octets[2]) + "." +
        std::to_string(this->octets[3]);
}
