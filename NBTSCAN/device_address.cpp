#include "device_address.h"

ipv4_range device_address::get_range()
{
    // Temporary fix
    if (mask.octets[0] == 255 &&
        mask.octets[1] == 255 &&
        mask.octets[2] == 255 &&
        mask.octets[3] == 0)
    {
        ipv4_range range;
        range.from.octets[0] = ip.octets[0];
        range.to.octets[0] = ip.octets[0];

        range.from.octets[1] = ip.octets[1];
        range.to.octets[1] = ip.octets[1];

        range.from.octets[2] = ip.octets[2];
        range.to.octets[2] = ip.octets[2];

        range.from.octets[3] = 0;
        range.to.octets[3] = 255;

        return range;
    }

    return ipv4_range();
    
}
