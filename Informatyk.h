#pragma once
#include "Pracownik.h"

class Informatyk : public Pracownik {
private:
    Napis m_TworzonaAplikacja; // Aktualnie tworzona aplikacja
    int m_nLiczbaAplikacji;    // Liczba stworzonych aplikacji

public:
    // Konstruktor domyślny
    Informatyk(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000,
        const char* aplikacja = "", int liczbaAplikacji = 0);

    // Konstruktor kopiujący
    Informatyk(const Informatyk& wzor);

    // Operator przypisania
    Informatyk& operator=(const Informatyk& wzor);

    // Operator porównania
    bool operator==(const Informatyk& wzor) const;

    // Wirtualna metoda wypisująca dane
    virtual void WypiszDane() const override;

    // Wirtualna metoda kopiująca obiekt
    virtual Pracownik* KopiaObiektu() const override;

    // Operator wstawiania do strumienia
    friend std::ostream& operator<<(std::ostream& wy, const Informatyk& i);

    // Operator pobierania ze strumienia
    friend std::istream& operator>>(std::istream& we, Informatyk& i);
};
