#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.h"
#include <tuple>

using namespace std;
/*
void srednia(vector<int> liczby) {
    int suma = 0;
    int dlugosc = liczby.size();
    for_each(liczby.begin(), liczby.end(), [&suma](int el) {
        suma = suma + el;
    });
    auto srednia = [&dlugosc](int suma) -> int {
        int srednia = suma / dlugosc;
        return srednia;
    };
    cout << srednia(suma) << endl;
}

void wstawianie(vector<int> liczby) {
    for_each(liczby.begin(), liczby.end(), [](int el) {cout << "|" << el; });
    cout << endl;
}

void elementyParzyste(vector<int> liczby) {
    int wynik = 0;
    for_each(liczby.begin(), liczby.end(), [&wynik](int el){
        if (el % 2 == 0)
            wynik++;
    });
    cout << wynik;
}
*/
void zad1() {
    vector<int> liczby;
    liczby.push_back(3);
    liczby.push_back(5);
    liczby.push_back(7);
    liczby.push_back(9);
    liczby.push_back(18);
    liczby.push_back(-10);
    liczby.push_back(6);

    cout << "wstawianie :" << endl;
    for_each(liczby.begin(), liczby.end(), [](int el) {cout << "|" << el; });
    cout << endl;

    cout << "srednia:  " << endl;
    int suma = 0;
    int dlugosc = liczby.size();
    for_each(liczby.begin(), liczby.end(), [&suma](int el) {
        suma = suma + el;
        });
    auto srednia = [&dlugosc](int suma) -> int {
        int srednia = suma / dlugosc;
        return srednia;
    };
    cout << srednia(suma) << endl;

    cout << "liczba elementow parzystych: " << endl;
    int wynik = 0;
    for_each(liczby.begin(), liczby.end(), [&wynik](int el) {
        if (el % 2 == 0)
            wynik++;
    });
    cout << wynik << endl;

    cout << "usunac ujemne: " << endl;
    int liczba = 0;
    for_each(liczby.begin(), liczby.end(), [&liczby, &liczba](int el) {
        if (el < 0)
            liczby.erase(liczby.begin()+liczba);
        liczba++;
    });
    for_each(liczby.begin(), liczby.end(), [](int el) {cout << el << endl; });
    
    vector<int> pom;
    int liczba2 = 0;
    cout << "elementy parzyste i nie parzyste: " << endl;
    for_each(liczby.begin(), liczby.end(), [&liczby, &liczba2](int el) {
        liczby.erase(liczby.begin() + liczba2);
        if (el % 2 != 0)
            liczby.push_back(el);
        else
            liczby.insert(liczby.begin(), el);
        liczba2++;
    });
    for_each(liczby.begin(), liczby.end(), [](int el) {cout << el << endl; });
    /*
    for_each(liczby.begin(), liczby.end(), [&pom](int el) {
        if (el % 2 != 0)
            pom.push_back(el);
    });
    */
    int liczba3 = 0;
    cout << "nadpisanie elementu liczba przeciwna: " << endl;
    for_each(liczby.begin(), liczby.end(), [&liczby, &liczba3](int el) {
        liczby.erase(liczby.begin() + liczba3);
        liczby.insert(liczby.begin() + liczba3, -el);
        liczba3++;
    });
    for_each(liczby.begin(), liczby.end(), [](int el) {cout << el << endl; });

    cout << "policzenie ile jest elementow jest mniejszych niz otrzymany argument" << endl;
    int argument = -5;
    int suma2 = 0;
    for_each(liczby.begin(), liczby.end(), [&liczby, &argument, &suma2](int el) {
        if (el < argument)
            suma2++;
    });
    cout << suma2;
}

void zad2() {
    vector<Car> cars;
    Car c1 = Car("Opel", 2001, 1.6);
    Car c2 = Car("Mazda", 1996, 2.0);
    Car c3 = Car("Ford", 2006, 2.5);
    cars.push_back(c1);
    cars.push_back(c2);
    cars.push_back(c3);
    
    cout << "Samochody: " << endl;
    for_each(cars.begin(), cars.end(), [](Car el) { el.wysiwietl(); });
    
    cout << "posrtowane wzgledem roku produkcji: " << endl;
    sort(cars.begin(), cars.end(), [](Car a, Car b) -> bool {
        return a.getRok() < b.getRok();
    });
    for (int i = 0; i < cars.size(); i++)
        cars[i].wysiwietl();
    
    cout << "posortowane wzgledem pojemnosci silnika: " << endl;
    sort(cars.begin(), cars.end(), [](Car a, Car b) -> bool {
        return a.getPojemnosc() > b.getPojemnosc();
    });
    for (int i = 0; i < cars.size(); i++)
        cars[i].wysiwietl();
}

tuple<int, int, string > napisy(vector<string> napisy) {
    int najmniejszy = napisy[0].size();
    for_each(napisy.begin(), napisy.end(), [&najmniejszy](string el) {
        if (el.size() < najmniejszy)
            najmniejszy = el.size();
        });

    double suma = 0;
    for_each(napisy.begin(), napisy.end(), [&suma](string el) {
        suma = suma + el.size();
        });
    int wynik = suma / napisy.size();

    string najdluzszy;
    int najwiekszy = napisy[0].size();
    for_each(napisy.begin(), napisy.end(), [&najdluzszy, &najwiekszy](string el) {
        if (el.size() > najwiekszy) {
            najwiekszy = el.size();
            najdluzszy = el;
        }
    });
    return { najmniejszy, wynik, najdluzszy };
}

void zad3() {
    vector<string> napis;
    napis.push_back("jebanie");
    napis.push_back("nie");
    napis.push_back("japierdole");
    cout << "dlugosc najkrotszego napisu: " << get<0>(napisy(napis)) << endl;
    cout << "srednia dlugosc napisu: " << get<1>(napisy(napis)) << endl;
    cout << "najdluzszy napis: " << get<2>(napisy(napis)) << endl;
}

int main() {
    //zad1();
    //zad2();
    zad3();
}
