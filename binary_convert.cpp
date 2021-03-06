#include "binary_convert.h"
using namespace std;

bool CheckString(string bin, int n)
{
    if (bin.length() != n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (bin[i] != '1' && bin[i] != '0')
        {
            return false;
        }
    }
    return true;
}
string InputBinString(int n)
{
    cin.ignore(256, '\n');
    bool check = true;
    string bin;
    cout << "Insert your binary string: ";
    getline(cin, bin);
    check = CheckString(bin, n);
    while (check == false || cin.fail())
    {
        cin.ignore(256,'\n');
        cin.clear();
        cout << "Insert your binary string: ";
        getline(cin, bin);
        check = CheckString(bin, n);
       
    }
    return bin;
}

void BtoUSC()
{
    string bin = InputBinString(8);
    bitset<8> bit(bin);
    cout << "Your binary string :" << bin << endl
         << "Your unsigned char number: " << bit.to_ulong() << endl;
}
void BtoUSS()
{
    string bin = InputBinString(16);
    bitset<16> bit(bin);
    cout << "Your binary string :" << bin << endl
         << "Your unsigned short number: " << bit.to_ulong() << endl;
}
void BtoSC()
{
    string bin = InputBinString(8);
    bitset<8> bit(bin);
    string tmp;
    if (bin[0] == '1')
    {
        bit.flip();
        tmp = bit.to_string();
        for (int i = 1; i < 8; i++)
        {
            tmp += to_string(bit[i]);
        }
        bitset<8> bit1(tmp);
        cout << "Your binary string :" << bin << endl
             << "Your signed char number: -" << bit1.to_ulong() + 1 << endl;
    }
    else
    {
        cout << "Your binary string :" << bin << endl
             << "Your signed char number: " << bit.to_ulong() << endl;
    }
}
void BtoSS()
{
    string bin = InputBinString(16);
    bitset<16> bit(bin);
    string tmp;
    if (bin[0] == '1')
    {
        bit.flip();
        tmp = bit.to_string();
        for (int i = 1; i < 16; i++)
        {
            tmp += to_string(bit[i]);
        }
        bitset<16> bit1(tmp);
        cout << "Your binary string :" << bin << endl
             << "Your signed short number: -" << bit1.to_ulong() + 1 << endl;
    }
    else
    {
        cout << "Your binary string :" << bin << endl
             << "Your signed short number: " << bit.to_ulong() << endl;
    }
}
void SStoB()
{
    long long x;
    cout << "Enter your signed short number: ";
    cin >> x;
    while (x > 32767 || x < -32168 || cin.fail())
    {
        cin.ignore('\n', 256);
        cout << "Enter your signed short number: ";
        cin >> x;
    }
    bitset<16> bit(x);
    cout << "Your signed short number: " << x << endl
         << "Your binary string: " << bit.to_string() << endl;
}
void UStoB()
{
    long long x;
    cout << "Enter your unsigned short number: ";
    cin >> x;
    while (x > 65535 || x < 0 || cin.fail())
    {
        cin.ignore('\n', 256);
        cout << "Enter your unsigned short number: ";
        cin >> x;
    }
    bitset<16> bit(x);
    cout << "Your unsigned short number: " << x << endl
         << "Your binary string: " << bit.to_string() << endl;
}
void SCtoB()
{
    long long x;
    cout << "Enter your signed char number: ";
    cin >> x;
    while (x > 127 || x < -128 || cin.fail())
    {
        cin.ignore('\n', 256);
        cout << "Enter your signed char number: ";
        cin >> x;
    }
    bitset<8> bit(x);
    cout << "Your signed char number: " << x << endl
         << "Your binary string: " << bit.to_string() << endl;
}
void UCtoB()
{
    long long x;
    cout << "Enter your unsigned char number: ";
    cin >> x;
    while (x > 255 || x < 0 || cin.fail())
    {
        cin.ignore('\n', 256);
        cout << "Enter your unsigned char number: ";
        cin >> x;
    }
    bitset<8> bit(x);
    cout << "Your unsigned char number: " << x << endl
         << "Your binary string: " << bit.to_string() << endl;
}

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
        while (!(dec_tmp < 1))
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
        while (!(dec_tmp < 1))
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
    dec = mantissa * pow(2, E);
    dec *= sign;
    return dec;
}

double Double_dec(std::bitset<64> bin)
{
    int E, sign = 1;
    unsigned long long mantissa;
    double dec;
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
    mantissa = tmp.to_ullong();
    cout << sign << endl;
    dec = mantissa * pow(2, E);
    dec *= sign;
    return dec;
}