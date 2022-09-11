
 #include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");

    char symbol_1;
    char symbol_2;
    int i = 0;
    ifstream fin,finshifr;
    ofstream foutshifr,foutdeshifr;
    string key;

    fin.open("ShortText.txt");
    foutshifr.open("Shifr.txt");
    cout << "Введите ключ для кодирования:";

    getline(cin, key);
    

    while (fin.get(symbol_1))
    {
        foutshifr << char(key[i] + symbol_1);
        if (i == key.length() - 1)
            i = 0;
        else
            i++; 
    };
    foutshifr.close();

    i = 0;
    finshifr.open("Shifr.txt");
    foutdeshifr.open("Deshifr.txt");
    cout << "Введите ключ для раскодирования:";
    getline(cin, key);

    while (finshifr.get(symbol_2))
    {
        foutdeshifr << char(symbol_2 - key[i]);
        if (i == key.length() - 1)
            i = 0;
        else
            i++;
    };


    fin.close();
    foutdeshifr.close();
    finshifr.close();
    
    return 0;
}  
