//
//  main.hpp
//  Financial Calculator
//
//  Created by Maciej Łukasik on 15.01.2020.
//  Copyright © 2019 Maciej Łukasik. All rights reserved.
//

#include <iostream>

#include "financial_calc.hpp"

using namespace std;

void start()
{
    Financial_calculator calculator;
    short metoda;
    char wybor;
    string tmp;

    cout << "Kalkulator finansowy 2000" << endl;

    cout << "Podaj imie : ";
    cin >> tmp;
    calculator.setImie(tmp);
    cout << "Podaj nazwisko : ";
    cin >> tmp;
    calculator.setNazwisko(tmp);
    cout << "Witaj " << calculator.getImie() << " " << calculator.getNazwisko()  << endl;
    
    do{
        metoda = 0;
        while ((cout << "Wybierz metodę oszczędzania:\n[1] - renta\n[2] - lokata\n") && !(cin >> metoda)) {
            cout << "To nie jest liczba " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(metoda)
        {
            case 1:
                calculator.renta();
                break;
            case 2:
                calculator.lokata();
                break;
            default:
                cout << "Błąd!" <<endl;
                break;
        }
    } while(metoda!=1 || metoda!=2);  
}

int main(int argc, const char * argv[]) {
    
    // while(1)
    // {
        start();
    // }

    return 0;
}