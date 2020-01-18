//
//  financial_calc.cpp
//  Financial Calculator
//
//  Created by Maciej Łukasik on 15.01.2020.
//  Copyright © 2019 Maciej Łukasik. All rights reserved.
//

#include "financial_calc.hpp"

#include <cmath>

using namespace std;

void Financial_calculator::renta()
{
    while ((cout << "Podaj czestosc platnosci w roku (1-12): ") && (!(cin >> k) || k < 1 || k > 12)) {
        cout << "Nie podales liczby z przedzialu od 1 do 12" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj czas trwania (w latach): ") && (!(cin >> l) || l <= 0)) {
        cout << "Podaj liczbę większą od 0" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj wartosc pojedynczej platnosci: ") && (!(cin >> pmt) || pmt < 100 )) {
        cout << "Minimalna kwota to 100" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj oprocentowanie renty: ") && (!(cin >> r) || r <= 0)) {
        cout << "Podaj liczbę większą od 0" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    do {
        cout << "Czy renta platna z gory [G] czy z dolu [D]? Wybierz [G] lub [D]: ";
        cin >> wybor;
        
        if(wybor == 'G' || wybor == 'g')
        {
            fv=pmt*(1+(r/(100*k)))*(((pow((1+(r/(100*k))), (l*k)))-1)/(r/(100*k)));
            rata_dane();
            cout << "Watosc przyszla renty platnej z gory po " << l << " latach przy " << k << " platnosciach w roku wynosi " << fv << " zl." << endl;
            cout << "---------------------" << endl; 
            break;
        }
        else if(wybor == 'D' || wybor == 'd')
        {
            fv=pmt*(((pow((1+(r/(100*k))), (l*k)))-1)/(r/(100*k)));
            rata_dane();
            cout << "Watosc przyszla renty platnej z dolu po " << l << " latach przy " << k << " platnosciach w roku wynosi " << fv << " zl." << endl;
            cout << "---------------------" << endl; 
            break;
        }
    } while(true);
    ponow();
}

void Financial_calculator::lokata()
{
    while ((cout << "Podaj kwotę poczatkowa: ") && (!(cin >> kwotal) || kwotal < 1000)) {
        cout << "Minimalna kwota lokaty to 1000" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj czas trwania lokaty (w latach): ") && (!(cin >> latal) || latal <= 0)) {
        cout << "Podaj liczbę większą od 0" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj oprocentowanie lokaty: ") && (!(cin >> procl) || procl <= 0)) {
        cout << "Podaj liczbę większą od 0" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Podaj czestosc kapitalizacji (1-360): ") && (!(cin >> kapitall) || kapitall < 1 || kapitall > 360)) {
        cout << "Nie podales liczby z przedzialu od 1 do 360" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    kwotak=kwotal*pow((1+(procl/(100*kapitall))), (latal*kapitall));                                      // funkcja POW(DOUBLE,DOUBLE) -  potegi z liczbami zmiennoprzecinkowymi
    
    cout << "---------------------" << endl;
    cout << imie << " " << nazwisko << endl;
    cout << "Kwota poczatkowa: " << kwotal << " zl." << endl;
    cout << "Lata: " << latal << endl;
    cout << "Oprocentowanie: " << procl << " %" << endl;
    cout << "Kapitalizacja: " << kapitall << endl;
    cout << "Koncowa wartosc lokaty po " << latal << " latach i kapitalizacji " << kapitall << " dniowej wynosi " << kwotak << " zl." << endl;
    cout << "---------------------" << endl;
    ponow();
}

void Financial_calculator::rata_dane()
{
    cout << "---------------------" << endl;
    cout << imie << " " << nazwisko << endl;
    cout << "Czestosc platnosci w roku: " << k << endl;
    cout << "Czas trwania: " << l << endl;
    cout << "Wartosc pojedynczej platnosci: " << pmt << endl;
    cout << "Oprocentowanie renty: " << r << " %" << endl;
}

void Financial_calculator::ponow()
{
    char wyb;
    cout << "Czy chcesz przeprowadzić jeszcze obliczenia?" << endl << "[T] - TAK" << endl << "[N] - NIE, zakończ program\n";
    cin >> wyb;

    if(!(wyb == 't' || wyb == 'T'))
    {
        cout << "Miłego dnia!" << endl;
        exit(0);
    }
}