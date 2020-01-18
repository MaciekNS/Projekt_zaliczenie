//
//  financial_calc.hpp
//  Financial Calculator
//
//  Created by Maciej Łukasik on 15.01.2020.
//  Copyright © 2019 Maciej Łukasik. All rights reserved.
//

#include <iostream>

class Financial_calculator
{
public:
    void renta();
    void lokata();
    void setImie(std::string imie) { this->imie = imie; }
    std::string getImie() const { return imie; }
    void setNazwisko(std::string nazwisko) { this->nazwisko = nazwisko; }
    std::string getNazwisko() const { return nazwisko; }


private:
    void rata_dane();
    void ponow();

    std::string imie, nazwisko;
    double kwotal, kwotak, pmt, fv;
    float latal, procl, kapitall, r;
    int k, l;
    short metoda;
    char wybor;
};