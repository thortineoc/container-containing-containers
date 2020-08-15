#pragma once
#include <string>
using namespace std;

class Przepelnienie: public exception {
    const char* nazwa;
    double num;
public:
    Przepelnienie(double r);
    const char* what() const noexcept; // przeladowanie z klasy exception
    double errNo();
};

class Dekonstrukcja: public exception {
    const char* nazwa;
public:
    Dekonstrukcja();
    const char* what() const noexcept;
};

class Pojemnik {
    double zawartosc;
    double pojemnosc;
    string nazwa;
public:
    Pojemnik(double);
    double pokaz_pojemnosc() const;
    double pokaz_zawartosc() const;
    void dolej(double);
    double pobierz(double);
    string substancja(void) const;
    void substancja(string);
    bool min_objetosc(double);
    bool max_objetosc(double);
    Pojemnik(Pojemnik &p)=delete;
    Pojemnik &operator=(Pojemnik &p)=delete;
};
ostream &operator<<(ostream &out, const Pojemnik &p);

struct node {
    Pojemnik* data;
    node* next;
    node* prev;
};

class Zasobnik {
    node* head, *tail;
    void lista_wstaw(double poj); // wstawia element na koniec listy
    void lista_usun(); // usuwa ostatni element z listy
public:
    Zasobnik();
    ~Zasobnik();
    void dodaj(double, size_t = 1);
    double usun(size_t = 1);
    void dolej(double);
    double pobierz(double);
    string substancja(void);
    void substancja(string);
    bool min_objetosc(double);
    bool max_objetosc(double);
    size_t liczba_pojemnikow();
    double pojemnosc();
    double zajetosc();
    Zasobnik(Zasobnik &)=delete; // zabronione kopiowanie
    Zasobnik &operator=(Zasobnik &)=delete;

    friend ostream &operator<<(ostream &out, const Zasobnik &z); // zeby mial dostep do head
};
