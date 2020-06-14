#include <iostream>
#include "zasobnik.h"

Zasobnik::Zasobnik() {
    head = nullptr;
    tail = nullptr;
}

void Zasobnik::wstawPoj(Pojemnik* p) {
    node* temp = new node;
    temp->data = p; // przypisuje wskaznikiem zeby uniknac kopiowania
    temp->next = nullptr;
    if(head == nullptr) { // jezeli pusta
        head = temp; // wskazuje na niego glowa
    } else {
        tail->next = temp; // wskazuje na niego poprzedni
    }
    tail = temp; // wskazuje na niego ogon
}

void Zasobnik::usunPoj(Pojemnik *p) {

}

void Zasobnik::dodaj(double poj, size_t ilosc) {
    for(int i=0; i<ilosc; i++) {
        Pojemnik* p = new Pojemnik(poj);
        wstawPoj(p);
    }
}

ostream &operator<<(ostream &out, Zasobnik &z) {
    out << "Pojemniki:" << endl;
    node* ptr = z.head;
    for(unsigned int i=0; i<z.liczba_pojemnikow(); i++) {
        out << "Oto opis pojemnika nr " << i+1 << endl;
        out << "Jego pojemnosc wynosi " << ptr->data->pokazPojemnosc() << " litrow" << endl;
        out << "Jest w nim aktualnie " << ptr->data->pokazZawartosc() << " litrow plynu" << endl;
        if(!ptr->data->substancja().empty()) {
            out << "Ten plyn to " << ptr->data->substancja() << endl;
        }
        ptr = ptr->next;
    }
    return out;
}

size_t Zasobnik::liczba_pojemnikow() { // ilość elementów na liście,
    size_t sum = 0;
    node* ptr = head;
    while(ptr) {
        sum++;
        ptr = ptr->next;
    }
    return sum;
}

void Zasobnik::dolej(double ilosc) {
    double reszta = ilosc;
    node* ptr = head;
    for(unsigned int i=0; i<liczba_pojemnikow(); i++) {
        if(ptr->data->pokazZawartosc() == ptr->data->pokazPojemnosc()) { // jezeli pelen
            ptr = ptr->next;
            continue; // przechodze do kolejnego jezeli ten pelen
        }
        try {
            ptr->data->dolej(reszta);
            return; // jak sie uda wlac do koncze funkcje
        } catch(Przepelnienie &ex) {
            cout << "Za duzo o " << ex.errNo() << " litrow" << endl;
            reszta = ex.errNo(); // tyle zostalo do wlania
            ptr = ptr->next;
        }
    }
    throw Przepelnienie(reszta); // jezeli tu dojdzie to nie udalo sie wlac calosci
}

double Zasobnik::pobierz(double ilosc) {
    double sum = 0;
    double do_pobrania = ilosc;
    for(long i=(long)liczba_pojemnikow(); i>=0; i--) { // od konca sprawdzam
        if(pojemniki[i]->zawartosc == 0) { // jezeli jest pusty
            continue;
        }
        if(pojemniki[i]->zawartosc >= do_pobrania) { // moge pobrac do konca
            pojemniki[i]->zawartosc -= do_pobrania;
            sum += do_pobrania;
            return sum;
        }
        // jezeli chce pobrac wiecej niz moge
        sum += pojemniki[i]->zawartosc; // pobieram wszystko z obecnego pojemnika
        do_pobrania -= pojemniki[i]->zawartosc;
        pojemniki[i]->zawartosc = 0;
    }
    return sum; // tu jak chce pobrac wiecej niz moge gdy jestem przy pierwszym lub skonczy na pustym
}










string Zasobnik::substancja() {
    return head->data->substancja();
}

void Zasobnik::substancja(string str) {
    try {
        head->data->substancja(str);
    } catch(int ex) {
        cout << "Wyjatek, nie mozna zmienic nazwy substancji, err=" << ex << endl;
    }
}

double Zasobnik::pojemnosc() { // sumaryczna pojemność kontenera,
    double sum = 0;
    node* ptr = head;
    while(ptr){
        sum += ptr->data->pokazPojemnosc();
        ptr = ptr->next;
    }
    return sum;
}

double Zasobnik::zajetosc() { // sumaryczna pojemność kontenera,
    double sum = 0;
    node* ptr = head;
    while(ptr){
        sum += ptr->data->pokazZawartosc();
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
