#include <iostream>
#include "zasobnik.h"

int main() {
    Zasobnik z1;
    z1.dodaj(5,3);
<<<<<<< HEAD
    cout << "Liczba pojemnikow: " << z1.liczba_pojemnikow() << endl;
=======
    cout << "Licza pojemnikow: " << z1.liczba_pojemnikow() << endl;
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    cout << z1;
    z1.substancja("sok");

    try {
        z1.dolej(12);
    } catch(Przepelnienie &ex) {
        cout << "UWAGA! Wyjatek typu " << ex.what() << endl;
<<<<<<< HEAD
        cout << "Plyn nie zmiescil sie we wszystkich pojemnikach. Zostalo " << ex.errNo() << " litr/y/ow" << endl;
=======
        cout << "Plyn nie zmiescil sie we wszystkich pojemnikach. Zostalo " << ex.errNo() << " litrow" << endl;
>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    }
    cout << z1;

    z1.substancja("olej");
    cout << "Plyn znajdujacy sie w pierwszym pojemniku owego zasobnika to " << z1.substancja() << endl;

<<<<<<< HEAD
=======

>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    cout << "Zajetosc " << z1.zajetosc() << endl;
    cout << "Pojemnosc " << z1.pojemnosc() << endl;

    double min = 17;
    double max = 3;
    if(z1.min_objetosc(min)) {
<<<<<<< HEAD
        cout << "Pojemniki zawieraja wiecej lub dokladnie " << min << " litr/y/ow plynu" << endl;
    } else {
        cout << "Pojemniki zawieraja mniej plynu niz " << min << " litr/y/ow" << endl;
    }
    if(z1.max_objetosc(max)) {
        cout << "Mozna dolac " << max << " litr/y/ow plynu" << endl;
    } else {
        cout << "Nie mozna dolac " << max << " litr/y/ow plynu" << endl;
    }

    cout << "Pobieram plyn" << endl;
    double pobrano = z1.pobierz(10);
    cout << z1;
    cout << "Pobrano " << pobrano << " litr/y/ow cieczy" << endl;
    cout << "Pobieram plyn jeszcze raz" << endl;
    pobrano = z1.pobierz(50);
    cout << "Pobrano " << pobrano << " litr/y/ow cieczy" << endl;

    try {
        z1.dolej(16);
    } catch(Przepelnienie &ex) {
        cout << "UWAGA! Wyjatek typu " << ex.what() << endl;
        cout << "Plyn nie zmiescil sie we wszystkich pojemnikach. Zostalo " << ex.errNo() << " litr/y/ow" << endl;
    }
    cout << z1;

    z1.pobierz(6);
    try {
        double res = z1.usun(2);
        cout << "Usunieto pojemniki o sumarycznej objetosci " << res << endl;
    } catch(Dekonstrukcja &ex) {
        cout << "UWAGA! Wyjatek typu " << ex.what() << endl;
    }
    cout << z1;

    //Zasobnik z2 = z1;
=======
        cout << "Pojemniki zawieraja wiecej lub dokladnie " << min << " litrow plynu" << endl;
    } else {
        cout << "Pojemniki zawieraja mniej plynu niz " << min << " litrow" << endl;
    }
    if(z1.max_objetosc(max)) {
        cout << "Mozna dolac " << max << " litrow plynu" << endl;
    } else {
        cout << "Nie mozna dolac " << max << " litrow plynu" << endl;
    }




>>>>>>> d28cd7621256a6b4d85846a1a2d29327860a77ad
    return 0;
}
