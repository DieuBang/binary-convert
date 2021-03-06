#include <iostream>
#include <bitset>
#include <string>
using namespace std;

bool CheckString(string bin, int n) {
	if (bin.length() != n) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (bin[i] != '1' && bin[i] != '0') {
			return false;
		}
	}
	return true;
}
string InputBinString(int n) {
	bool check = true;
	string bin;
	cout << "Insert your binary string: ";
	getline(cin, bin);
	while (check || cin.fail()) {
		cin.clear();
		cout << "Insert your binary string: ";
		getline(cin, bin);
		check = CheckString(bin, n);
	}
	return bin;
}

void BtoUSC() {
	string bin = InputBinString(8);
	bitset<8> bit(bin);
	cout << "Your binary string :" << bin << endl << "Your unsigned char number: " << bit.to_ulong() << endl;
}
void BtoUSS() {
	string bin = InputBinString(16);
	bitset<16> bit(bin);
	cout << "Your binary string :" << bin << endl << "Your unsigned short number: " << bit.to_ulong() << endl;
}
void BtoSC() {
	string bin = InputBinString(8);
	bitset<8> bit(bin);
	string tmp;
	if (bin[0] == '1') {
		bit.flip();
		tmp = bit.to_string();
		for (int i = 1; i < 8; i++) {
			tmp += to_string(bit[i]);
		}
		bitset <8> bit1(tmp);
		cout << "Your binary string :" << bin << endl << "Your signed char number: -" << bit1.to_ulong() + 1  << endl;
	}
	else {
		cout << "Your binary string :" << bin << endl << "Your signed char number: " << bit.to_ulong() << endl;
	}
}
void BtoSS() {
	string bin = InputBinString(16);
	bitset<16> bit(bin);
	string tmp;
	if (bin[0] == '1') {
		bit.flip();
		tmp = bit.to_string();
		for (int i = 1; i < 16; i++) {
			tmp += to_string(bit[i]);
		}
		bitset <16> bit1(tmp);
		cout << "Your binary string :" << bin << endl << "Your signed short number: -" << bit1.to_ulong() + 1 << endl;
	}
	else {
		cout << "Your binary string :" << bin << endl << "Your signed short number: " << bit.to_ulong() << endl;
	}

}
void SStoB() {
	long long x;
	cout << "Enter your signed short number: ";
	cin >> x;
	while (x > 32767 || x < -32168 || cin.fail()) {
		cin.ignore('\n', 256);
		cout << "Enter your signed short number: ";
		cin >> x;
	}
	bitset<16> bit(x);
		cout << "Your signed short number: " << x << endl << "Your binary string: " << bit.to_string() << endl;

}
void UStoB() {
	long long x;
	cout << "Enter your unsigned short number: ";
	cin >> x;
	while (x > 65535 || x < 0 || cin.fail()) {
		cin.ignore('\n', 256);
		cout << "Enter your unsigned short number: ";
		cin >> x;
	}
	bitset<16> bit(x);
	cout << "Your unsigned short number: " << x << endl << "Your binary string: " << bit.to_string() << endl;

}
void SCtoB() {
	long long x;
	cout << "Enter your signed char number: ";
	cin >> x;
	while (x > 127 || x < -128 || cin.fail()) {
		cin.ignore('\n', 256);
		cout << "Enter your signed char number: ";
		cin >> x;
	}
	bitset<8> bit(x);
	cout << "Your signed char number: " << x << endl << "Your binary string: " << bit.to_string() << endl;

}
void UCtoB() {
	long long x;
	cout << "Enter your unsigned char number: ";
	cin >> x;
	while (x > 255 || x < 0 || cin.fail()) {
		cin.ignore('\n', 256);
		cout << "Enter your unsigned char number: ";
		cin >> x;
	}
	bitset<8> bit(x);
	cout << "Your unsigned char number: " << x << endl << "Your binary string: " << bit.to_string() << endl;

}
int main() {
	string tmp = "01111111";
	SStoB();
	

	return 0;
}