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

<<<<<<< HEAD
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
=======
ostream &operator<<(ostream &out, Pojemnik &p) {
    out << "Oto opis twojego pojemnika!" << endl;
    out << "Jego pojemnosc wynosi " << p.pojemnosc << " litrow" << endl;
    out << "Jest w nim aktualnie " << p.zawartosc << " litrow plynu" << endl;
    if(!p.nazwa.empty()) {
        out << "Ten plyn to " << p.nazwa << endl;
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    }
    return out;
}

<<<<<<< HEAD
=======
Pojemnik::Pojemnik(double poj) {
    pojemnosc = poj;
    zawartosc = 0;
}

>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
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

<<<<<<< HEAD
=======
string Pojemnik::substancja() {
    return nazwa;
}

>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
void Pojemnik::substancja(string str) {
    if(!zawartosc) {
        nazwa = str;
    } else {
<<<<<<< HEAD
        string ex = "Substancja";
        throw ex;
=======
        throw -1;
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    }
}

bool Pojemnik::min_objetosc (double ilosc) {
    return zawartosc >= ilosc; // jezeli zawiera przynajmniej tyle to true
}

bool Pojemnik::max_objetosc(double ilosc) {
    return zawartosc + ilosc <= pojemnosc; // jezeli nie przekroczy to true
<<<<<<< HEAD
=======
}

double Pojemnik::pokazPojemnosc() {
    return pojemnosc;
}

double Pojemnik::pokazZawartosc() {
    return zawartosc;
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
}