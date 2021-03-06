#include "binary_convert.h"

int main()
{
    std::string bin_str;
    std::bitset<32> bin32;
    std::bitset<64> bin64;
    int choice, dec_Sint;
    unsigned int dec_Uint;
    float dec_Float;
    double dec_Double;
    while (true)
    {
        std::cout << "1. Unsigned char (8-bit) Decimal to Binary\n";
        std::cout << "2. Unsigned char (8-bit) Binary to Decimal\n";
        std::cout << "3. Signed char (8-bit) Decimal to Binary\n";
        std::cout << "4. Signed char (8-bit) Binary to Decimal\n";
        std::cout << "5. Unsigned short (16-bit) Decimal to Binary\n";
        std::cout << "6. Unsigned short (16-bit) Binary to Decimal\n";
        std::cout << "7. Signed short (16-bit) Decimal to Binary\n";
        std::cout << "8. Signed short (16-bit) Binary to Decimal\n";
        std::cout << "9. Unsigned int (32-bit) Decimal to Binary\n";
        std::cout << "10. Unsigned int (32-bit) Binary to Decimal\n";
        std::cout << "11. Signed int (32-bit) Decimal to Binary\n";
        std::cout << "12. Signed int (32-bit) Binary to Decimal\n";
        std::cout << "13. Float (Single precision 32-bit) Decimal to Binary\n";
        std::cout << "14. Float (Single precision 32-bit) Binary to Decimal\n";
        std::cout << "15. Double (Double precision 64-bit) Decimal to Binary\n";
        std::cout << "16. Double (Double precision 64-bit) Binary to Decimal\n";
        std::cout << "0. Exit\n";
        std::cout << "You choose: ";
        std::cin >> choice;
        while (choice > 16 || choice < 0 || std::cin.fail())
        {
            std::cin.ignore(256, '\n');
            std::cout << "You choose: ";
            std::cin >> choice;
 
        }
        if (choice == 0)
        {
            break;
        }
        std::cout << '\n';
        switch (choice)
        {
        case 1:
            UCtoB();
            break;
        case 2:
            BtoUSC();
            break;
        case 3:
            SCtoB();
            break;
        case 4:
            BtoSC();
            break;
        case 5:
            UStoB();
            break;
        case 6:
            BtoUSS();
            break;
        case 7:
            SStoB();
            break;
        case 8:
            BtoSS();
            break;
        case 9:
            std::cout << "Enter your unsigned int number: ";
            std::cin >> dec_Uint;
            std::cin.ignore(256, '\n');
            std::cout << "Your binary string: " << Unsigned_int_bin(dec_Uint) << '\n';
            break;
        case 10:
            std::cout << "Enter your Binary string: ";
            std::cin >> bin32;
            std::cin.ignore(256, '\n');
            std::cout << "Your unsigned int number: " << Unsigned_int_dec(bin32) << '\n';
            break;
        case 11:
            std::cout << "Enter your signed int number: ";
            std::cin >> dec_Sint;
            std::cin.ignore(256, '\n');
            std::cout << "Your binary string: " << Signed_int_bin(dec_Uint) << '\n';
            break;
        case 12:
            std::cout << "Enter your Binary string: ";
            std::cin >> bin32;
            std::cin.ignore(256, '\n');
            std::cout << "Your signed int number: " << Signed_int_dec(bin32) << '\n';
            break;
        case 13:
            std::cout << "Enter your Float number: ";
            std::cin >> dec_Float;
            std::cin.ignore(256, '\n');
            std::cout << "Your binary string: " << Float_bin(dec_Float) << '\n';
            break;
        case 14:
            std::cout << "Enter your Binary string: ";
            std::cin >> bin32;
            std::cin.ignore(256, '\n');
            std::cout << "Your Float number: " << Float_dec(bin32) << '\n';
            break;
        case 15:
            std::cout << "Enter your Double number: ";
            std::cin >> dec_Double;
            std::cin.ignore(256, '\n');
            std::cout << "Your binary string: " << Double_bin(dec_Double) << '\n';
            break;
        case 16:
            std::cout << "Enter your Binary string: ";
            std::cin >> bin64;
            std::cin.ignore(256, '\n');
            std::cout << "Your Double number: " << Double_dec(bin64) << '\n';
            break;
        }
        std::cout << "\nContinue? (1 / 0): ";
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        while (choice > 1 || choice < 0 || std::cin.fail())
        {
            cin.ignore('\n', 256);
            std::cout << "\nContinue? (1 / 0): ";
            std::cin >> choice;
            std::cin.ignore(256, '\n');
        }
        if (choice == 0)
        {
            break;
        }
    }
    return 0;
}