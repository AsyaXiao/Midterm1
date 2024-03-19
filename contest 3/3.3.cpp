//
// Common suffix
//
#include <string>


std::string common_suffix(const std::string &a, const std::string &b) {
    std::string suffix;
    int len1 = a.size() - 1;
    int len2 = b.size() - 1;
    int k = 0;
    while (len1 >= 0 && len2 >= 0 && a[len1] == b[len2]) {
        --len1;
        --len2;
        ++k;
    }
    suffix = a.substr(a.size() - k, k);
    return suffix;
}