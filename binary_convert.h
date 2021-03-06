#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

std::bitset<32> Signed_int_bin(int dec);

std::bitset<32> Unsigned_int_bin(int dec);

int Signed_int_dec(std::bitset<32> bin);

unsigned int Unsigned_int_dec(std::bitset<32> bin);

std::bitset<32> Float_bin(float dec);

std::bitset<64> Double_bin(double dec);

float Float_dec(std::bitset<32> bin);

double Double_bin(std::bitset<64> bin);