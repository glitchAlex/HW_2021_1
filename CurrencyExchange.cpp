#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>;
#include <windows.h>;
using namespace std;

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    int input = 0;
    cout << "Select preferred language: " << endl
        << "1: English (US)" << endl
        << "2: English (UK) UNABLE" << endl //how to use GBP currency instead of XDR?
        << "3: Deutsch (DE)" << endl
        << "4: Russian (RU)" << endl;
        //<< "5: Japanese (JP)" << endl; //it's hard to display JP text. Maybe later.
    cin >> input;

    if (input == 1)
    {
        //setlocale(LC_ALL, "en_US.UTF8");
        cout.imbue(locale("en_US.UTF8"));
        cout << "English selected.\nPlease, enter the amount of money you wish to exchange in USD: ";
    }
    else if (input == 2222) //2222 code for alpha-test
    {
        //setlocale(LC_ALL, "en_UK.UTF8");
        cout.imbue(locale("en_UK.UTF8"));
        cout << "English selected.\nPlease, enter the amount of money you wish to exchange in USD: ";
    }
    else if (input == 3)
    {
        //setlocale(LC_ALL, "de_DE.UTF8");
        cout.imbue(locale("de_DE.UTF8"));
        cout << "Deutsch ausgewaehlt.\nBitte geben Sie den Geldbetrag, den Sie umtauschen moechten, in USD ein: "; //sorry for my Deutsch. I'm not that great. (used google translater anyway)
    }
    else if (input == 4)
    {
        //setlocale(LC_ALL, "ru_RU.UTF8");
        cout.imbue(locale("ru_RU.UTF8"));
        cout << "Русский выбран.\nПожалйуста, введите сумму денег, которую желаете обменять, в USD: ";
    }
    else {
        cout << "Wrong input" << endl
            << "Wrong input" << endl
            << "Wrong input" << endl;
        return 0;
    }
    
    double val = 0;
    cin >> val;

    //13.03.2021
    if (input == 2) //won't work because alpha test input is 2222
        val = 0.72 * val;
    else if (input == 3)
        val = 0.84 * val;
    else if (input == 4)
        val = 73.26 * val;

    cout << showbase << put_money(val, true);
}
