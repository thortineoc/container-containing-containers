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

class Dekonstrukcja: public exception{
    const char* nazwa;
public:
    Dekonstrukcja();
    const char* what() const noexcept;
};

class Pojemnik {
    string nazwa;
    double pojemnosc;
    double zawartosc;
public:
    Pojemnik(double = 0);
    Pojemnik(Pojemnik &&);
    double pokazPojemnosc();
    double pokazZawartosc();
    void dolej(double);
    double pobierz(double);
    string substancja(void);
    void substancja(string);
    bool min_objetosc(double);
    bool max_objetosc(double);
    Pojemnik(Pojemnik &)=delete; // zabronione kopiowanie
    Pojemnik &operator=(Pojemnik &)=delete;

    friend ostream &operator<<(ostream &out, Pojemnik &p);
};

struct node {
    Pojemnik* data;
    node* next;
};

class Zasobnik {
    node* head;
    node* tail;
    void wstawPoj(Pojemnik* p);
    void usunPoj(Pojemnik* p);
    //clean
public:
    Zasobnik();
    //~Zasobnik();
    void dodaj(double, size_t = 1);
    double usun(size_t = 1);
    void dolej(double);
    double pobierz(double);
    string substancja(void);
    void substancja(string);
    bool min_objetosc(double);
    bool max_objetosc(double);
    size_t liczba_pojemnikow(); // ilość elementów na liście,
    double pojemnosc();  // sumaryczna pojemność kontenera,
    double zajetosc();
    Zasobnik(Zasobnik &)=delete; // zabronione kopiowanie
    Zasobnik &operator=(Zasobnik &)=delete;

    friend ostream &operator<<(ostream &out, Zasobnik &z);
};
