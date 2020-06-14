#include <iostream>
#include "zasobnik.h"

int main() {
    Zasobnik z1;
    z1.dodaj(5,3);
    cout << "Licza pojemnikow: " << z1.liczba_pojemnikow() << endl;
    cout << z1;
    z1.substancja("sok");

    try {
        z1.dolej(12);
    } catch(Przepelnienie &ex) {
        cout << "UWAGA! Wyjatek typu " << ex.what() << endl;
        cout << "Plyn nie zmiescil sie we wszystkich pojemnikach. Zostalo " << ex.errNo() << " litrow" << endl;
    }
    cout << z1;

    z1.substancja("olej");
    cout << "Plyn znajdujacy sie w pierwszym pojemniku owego zasobnika to " << z1.substancja() << endl;


    cout << "Zajetosc " << z1.zajetosc() << endl;
    cout << "Pojemnosc " << z1.pojemnosc() << endl;

    double min = 17;
    double max = 3;
    if(z1.min_objetosc(min)) {
        cout << "Pojemniki zawieraja wiecej lub dokladnie " << min << " litrow plynu" << endl;
    } else {
        cout << "Pojemniki zawieraja mniej plynu niz " << min << " litrow" << endl;
    }
    if(z1.max_objetosc(max)) {
        cout << "Mozna dolac " << max << " litrow plynu" << endl;
    } else {
        cout << "Nie mozna dolac " << max << " litrow plynu" << endl;
    }




    return 0;
}
