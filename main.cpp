#include "binary_convert.h"

int main()
{
    std::bitset<32> bin;
    double dec;
    std::cin >> bin;
    //std::cout << byte << '\n';
    //std::cout << Signed_int_bin(-2147483647) << '\n';
    std::cout << Float_dec(bin) << '\n';
    //std::cout << Double_bin(dec) << '\n';
    return 0;
}