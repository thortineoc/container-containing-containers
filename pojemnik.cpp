#include <iostream>
#include "zasobnik.h"

Przepelnienie::Przepelnienie(double r) {
    nazwa = "Przepelnienie";
    num = r;
}
const char* Przepelnienie::what() const noexcept { return nazwa; }
double Przepelnienie::errNo() { return num; };

Dekonstrukcja::Dekonstrukcja() { nazwa = "Dekonstrukcja"; };
const char* Dekonstrukcja::what() const noexcept { return nazwa; }

ostream &operator<<(ostream &out, Pojemnik &p) {
    out << "Oto opis twojego pojemnika!" << endl;
    out << "Jego pojemnosc wynosi " << p.pojemnosc << " litrow" << endl;
    out << "Jest w nim aktualnie " << p.zawartosc << " litrow plynu" << endl;
    if(!p.nazwa.empty()) {
        out << "Ten plyn to " << p.nazwa << endl;
    }
    return out;
}

Pojemnik::Pojemnik(double poj) {
    pojemnosc = poj;
    zawartosc = 0;
}

void Pojemnik::dolej(double ilosc) {
    if(zawartosc + ilosc > pojemnosc) {  // nie miesci sie
        double reszta = zawartosc + ilosc - pojemnosc;
        zawartosc = pojemnosc;
        throw Przepelnienie(reszta);
    }
    zawartosc += ilosc;
}

double Pojemnik::pobierz(double ilosc) {
    if(zawartosc < ilosc) { // jezeli chce pobrac wiecej niz jest
        double pobrano = zawartosc;
        zawartosc = 0;
        return pobrano;
    }
    zawartosc -= ilosc;
    return ilosc;
}

string Pojemnik::substancja() {
    return nazwa;
}

void Pojemnik::substancja(string str) {
    if(!zawartosc) {
        nazwa = str;
    } else {
        throw -1;
    }
}

bool Pojemnik::min_objetosc (double ilosc) {
    return zawartosc >= ilosc; // jezeli zawiera przynajmniej tyle to true
}

bool Pojemnik::max_objetosc(double ilosc) {
    return zawartosc + ilosc <= pojemnosc; // jezeli nie przekroczy to true
}

double Pojemnik::pokazPojemnosc() {
    return pojemnosc;
}

double Pojemnik::pokazZawartosc() {
    return zawartosc;
}