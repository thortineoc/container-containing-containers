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

<<<<<<< HEAD
class Dekonstrukcja: public exception {
=======
class Dekonstrukcja: public exception{
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    const char* nazwa;
public:
    Dekonstrukcja();
    const char* what() const noexcept;
};

class Pojemnik {
<<<<<<< HEAD
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
=======
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
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad

struct node {
    Pojemnik* data;
    node* next;
<<<<<<< HEAD
    node* prev;
};

class Zasobnik {
    node* head, *tail;
    void lista_wstaw(double poj); // wstawia element na koniec listy
    void lista_usun(); // usuwa ostatni element z listy
public:
    Zasobnik();
    ~Zasobnik();
=======
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
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    void dodaj(double, size_t = 1);
    double usun(size_t = 1);
    void dolej(double);
    double pobierz(double);
    string substancja(void);
    void substancja(string);
    bool min_objetosc(double);
    bool max_objetosc(double);
<<<<<<< HEAD
    size_t liczba_pojemnikow();
    double pojemnosc();
=======
    size_t liczba_pojemnikow(); // ilość elementów na liście,
    double pojemnosc();  // sumaryczna pojemność kontenera,
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    double zajetosc();
    Zasobnik(Zasobnik &)=delete; // zabronione kopiowanie
    Zasobnik &operator=(Zasobnik &)=delete;

<<<<<<< HEAD
    friend ostream &operator<<(ostream &out, const Zasobnik &z); // zeby mial dostep do head
=======
    friend ostream &operator<<(ostream &out, Zasobnik &z);
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
};
