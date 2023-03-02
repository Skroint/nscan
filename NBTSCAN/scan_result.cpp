#include "scan_result.h"

std::vector<found_host*> scan_result::found()
{
    std::vector<found_host*> f;

    for (int i = 0; i < count; i++)
    {
        if (found_matrix[i])
        {
            f.push_back(found_matrix[i]);
        }
    }

    return f;
}

scan_result scan_result::initialize(int count)
{
    scan_result sr;

    sr.count = count;
    sr.found_matrix = new found_host*[count];
    memset(&sr.found_matrix, 0, sizeof(found_host*) * count);

    return sr;
}
