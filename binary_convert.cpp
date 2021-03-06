#include "binary_convert.h"

std::bitset<32> Signed_int_bin(int dec)
{
    std::bitset<32> bin(dec);
    return bin;
}

std::bitset<32> Unsigned_int_bin(int dec)
{
    if (dec < 0)
    {
        dec = 0;
    }
    std::bitset<32> bin(dec);
    return bin;
}

int Signed_int_dec(std::bitset<32> bin)
{
    return bin.to_ulong();
}

unsigned int Unsigned_int_dec(std::bitset<32> bin)
{
    return bin.to_ulong();
}

std::bitset<32> Float_bin(float dec)
{
    float dec_tmp;
    bool sign = 0;
    std::bitset<32> bin;
    std::bitset<8> exponent;
    int count = 0;
    if (dec < 0)
    {
        sign = 1;
        dec = fabs(dec);
    }
    dec_tmp = dec;
    if (dec > 1)
    {
        while (dec_tmp > 1)
        {
            dec_tmp /= 2;
            ++count;
        }
        bin = dec * pow(2, 24 - count);
        exponent = 23 - (24 - count) + 127;
    }
    else if (dec > 0)
    {
        while (dec_tmp < 1)
        {
            dec_tmp *= 2;
            ++count;
        }
        bin = dec * pow(2, 23 + count);
        exponent = 23 - (23 + count) + 127;
    }
    else
    {
        return 0;
    }
    for (int i = 0; i < 8; ++i)
    {
        bin[23 + i] = exponent[i];
    }
    bin[31] = sign;
    return bin;
}

std::bitset<64> Double_bin(double dec)
{
    double dec_tmp;
    bool sign = 0;
    std::bitset<64> bin;
    std::bitset<11> exponent;
    int count = 0;
    if (dec < 0)
    {
        sign = 1;
        dec = fabs(dec);
    }
    dec_tmp = dec;
    if (dec > 1)
    {
        while (dec_tmp > 1)
        {
            dec_tmp /= 2;
            ++count;
        }
        bin = dec * pow(2, 53 - count);
        exponent = 52 - (53 - count) + 1023;
    }
    else if (dec > 0)
    {
        while (dec_tmp < 1)
        {
            dec_tmp *= 2;
            ++count;
        }
        bin = dec * pow(2, 53 + count);
        exponent = 53 - (53 + count) + 1023;
    }
    else
    {
        return 0;
    }
    for (int i = 0; i < 11; ++i)
    {
        bin[52 + i] = exponent[i];
    }
    bin[63] = sign;
    return bin;
}

float Float_dec(std::bitset<32> bin)
{
    int E, sign = 1;
    unsigned long mantissa;
    float dec;
    std::bitset<32> tmp(bin);
    if (bin[31] == 1)
    {
        sign = -1;
    }
    tmp <<= 1;
    tmp >>= 24;
    E = tmp.to_ulong() - 127 - 23;
    tmp = bin;
    tmp <<= 9;
    tmp >>= 9;
    tmp[23] = 1;
    mantissa = tmp.to_ulong();
    dec = sign * mantissa * pow(2, E);
    return dec;
}

double Double_dec(std::bitset<64> bin)
{
    int E, sign = 1;
    unsigned long mantissa;
    float dec;
    std::bitset<64> tmp(bin);
    if (bin[63] == 1)
    {
        sign = -1;
    }
    tmp <<= 1;
    tmp >>= 53;
    E = tmp.to_ulong() - 1023 - 52;
    tmp = bin;
    tmp <<= 12;
    tmp >>= 12;
    tmp[52] = 1;
    mantissa = tmp.to_ulong();
    dec = sign * mantissa * pow(2, E);
    return dec;
}