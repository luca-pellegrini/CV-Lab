#include "myutils.h"

#include <string>

std::string remove_extension_from_filename(const std::string &s)
{
    std::string::size_type ext_pos = s.rfind(".");
    std::string r = s.substr(0, ext_pos);
    return r;
}
