#pragma once
#include "Pracownik.h"
#include "Napis.h"

class Kierownik : public Pracownik {
private:
    Napis m_NazwaDzialu;
    int m_nLiczbaPracownikow;

public:
    // Konstruktor domyœlny
    Kierownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000,
        const char* nazwaDzialu = "", int liczbaPracownikow = 0);

    // Konstruktor kopiuj¹cy
    Kierownik(const Kierownik& wzor);

    // Operator przypisania
    Kierownik& operator=(const Kierownik& wzor);

    // Operator porównania
    bool operator==(const Kierownik& wzor) const;

    // Wirtualne metody
    virtual void WypiszDane() const;
    virtual Pracownik* KopiaObiektu() const override;

    // Operatory strumieniowe
    friend std::ostream& operator<<(std::ostream& wy, const Kierownik& k);
    friend std::istream& operator>>(std::istream& we, Kierownik& k);
};
    