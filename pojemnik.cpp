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

Pojemnik::Pojemnik(double poj): zawartosc(0), pojemnosc(poj), nazwa("") {}

double Pojemnik::pokaz_pojemnosc() const { return pojemnosc; }
double Pojemnik::pokaz_zawartosc() const { return zawartosc; }
string Pojemnik::substancja() const { return nazwa; }

ostream &operator<<(ostream &out, const Pojemnik &p) {
    out << "Oto opis twojego pojemnika!" << endl;
    out << "Jego pojemnosc wynosi " << p.pokaz_pojemnosc() << " litr/y/ow" << endl;
    out << "Jest w nim aktualnie " << p.pokaz_zawartosc() << " litr/y/ow plynu" << endl;
    if(!p.substancja().empty()) {
        out << "Ten plyn to " << p.substancja() << endl;
    }
    return out;
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

void Pojemnik::substancja(string str) {
    if(!zawartosc) {
        nazwa = str;
    } else {
        string ex = "Substancja";
        throw ex;
    }
}

bool Pojemnik::min_objetosc (double ilosc) {
    return zawartosc >= ilosc; // jezeli zawiera przynajmniej tyle to true
}

bool Pojemnik::max_objetosc(double ilosc) {
    return zawartosc + ilosc <= pojemnosc; // jezeli nie przekroczy to true
}