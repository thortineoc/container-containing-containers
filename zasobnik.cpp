#include <iostream>
#include "zasobnik.h"

Zasobnik::Zasobnik(): head(nullptr), tail(nullptr) {}
Zasobnik::~Zasobnik() {
    node* ptr = tail;
    while(ptr) {
        lista_usun();
        ptr = tail;
    }
}

ostream &operator<<(ostream &out, const Zasobnik &z) {
    out << "Pojemniki:" << endl;
    node* ptr = z.head;
    while(ptr) {
        out << *ptr->data; // wywolanie przeladowanej funkcji wypisujacej pojemnik
        ptr = ptr->next;
    }
    return out;
}

size_t Zasobnik::liczba_pojemnikow() {
    size_t sum = 0;
    node* ptr = head;
    while(ptr) {
        sum++;
        ptr = ptr->next;
    }
    return sum;
}

void Zasobnik::lista_wstaw(double poj) {
    node* temp = nullptr;
    try {
        temp = new node;
        temp->data = new Pojemnik(poj); // alokowanie zeby uniknac kopiowania
    } catch(bad_alloc &) {
        exit(EXIT_FAILURE);
    }
    temp->next = nullptr;
    if(head == nullptr) { // jezeli pusta
        tail = head = temp;
    } else {
        tail->next = temp; // wskazuje na niego poprzedni
        temp->prev = tail;
        tail = temp;
    }
}

void Zasobnik::dodaj(double poj, size_t ilosc) {
    for(unsigned int i=0; i<ilosc; i++) {
        Pojemnik p(poj); // tworze pojemnik o pojemnosci
        lista_wstaw(poj);
    }
}

void Zasobnik::lista_usun() {
    if(head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta";
        return;
    }
    node* temp = tail;
    if(head == tail) { // jeden element na liscie
        head = tail = nullptr;
        delete temp->data;
        delete temp;
    } else {
        temp = tail;
        tail->prev->next = nullptr; // zrywanie polaczenia
        tail = tail->prev;
        delete temp->data;
        delete temp;
    }
}

double Zasobnik::usun(size_t ilosc) {
    double sum = 0;
    node* ptr = tail;
    for(unsigned int i=0; i<ilosc; i++) {
        if(ptr) {
            if(ptr->data->pokaz_zawartosc() == 0) { // pusty
                sum += ptr->data->pokaz_pojemnosc();
                ptr = ptr->prev;
                lista_usun(); // usuwa z konca
            } else {
                throw Dekonstrukcja();
            }
        } else {
            cout << "Usunieto wszystkie pojemniki" << endl;
            break;
        }
    }
    return sum;
}

void Zasobnik::dolej(double ilosc) {
    double reszta = ilosc;
    node* ptr = head;
    for(unsigned int i=0; i<liczba_pojemnikow(); i++) {
        if(ptr->data->pokaz_zawartosc() == ptr->data->pokaz_pojemnosc()) { // jezeli pelen
            ptr = ptr->next;
            continue; // przechodze do kolejnego jezeli ten pelen
        }
        try {
            ptr->data->dolej(reszta);
            return; // jak sie uda wlac do koncze funkcje
        } catch(Przepelnienie &ex) {
            cout << "Za duzo o " << ex.errNo() << " litr/y/ow. Probuje przelac do kolejnego" << endl;
            reszta = ex.errNo(); // tyle zostalo do wlania
            ptr = ptr->next;
        }
    }
    throw Przepelnienie(reszta); // jezeli tu dojdzie to nie udalo sie wlac calosci
}

double Zasobnik::pobierz(double ilosc) {
    double pobrano = 0;
    double reszta = ilosc;
    node* ptr = tail;
    for(int i=(int)liczba_pojemnikow()-1; i>=0; i--) { // od konca sprawdzam
        if(ptr->data->pokaz_zawartosc() == 0) { // jezeli jest pusty nie moge pobrac, probuje z poprzedniego
            ptr = ptr->prev;
            continue;
        }
        pobrano += ptr->data->pobierz(reszta); // ilosc pobranej substancji z 1 poj
        if(pobrano == ilosc) { // jezeli to co pobrano to juz wszystko
            return pobrano;
        }
        // jezeli chce pobrac wiecej niz moge
        ptr = ptr->prev;
        reszta = ilosc - pobrano;
    }
    return pobrano; // tu jak chce pobrac wiecej niz moge gdy jestem przy pierwszym lub skonczy na pustym
}

string Zasobnik::substancja() { return head->data->substancja(); }
void Zasobnik::substancja(string str) {
    try {
        head->data->substancja(str);
    } catch(string ex) { // nie bylo podane w poleceniu jakiego typu wyjatek ma byc rzucany w tym miejscu
        cout << "UWAGA! Wyjatek, blad: " << ex << endl;
    }
}

double Zasobnik::pojemnosc() { // sumaryczna pojemność kontenera,
    double sum = 0;
    node* ptr = head;
    while(ptr) {
        sum += ptr->data->pokaz_pojemnosc();
        ptr = ptr->next;
    }
    return sum;
}

double Zasobnik::zajetosc() { // sumaryczna pojemność kontenera,
    double sum = 0;
    node* ptr = head;
    while(ptr) {
        sum += ptr->data->pokaz_zawartosc();
        ptr = ptr->next;
    }
    return sum;
}

bool Zasobnik::min_objetosc(double ilosc) { // jezeli pojemniki zawieraja tyle lub wiecej plynu
    return zajetosc() >= ilosc;
}

bool Zasobnik::max_objetosc(double ilosc) { // jezeli mozna dolac ilosc plynu
    return zajetosc() + ilosc <= pojemnosc();
}
