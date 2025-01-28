#pragma once
#include "Pracownik.h"
#include "Napis.h"

class Kierownik : public Pracownik {
private:
    Napis m_NazwaDzialu;
    int m_nLiczbaPracownikow;

public:
    Kierownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000, const char* nazwaDzialu = "", int liczbaPracownikow = 0);
    Kierownik(const Kierownik& wzor);

    Kierownik& operator=(const Kierownik& wzor);

    bool operator==(const Kierownik& wzor) const;

    void Wpisz();
    virtual void WypiszDane() const;
    virtual Pracownik* KopiaObiektu() const override;
    virtual const char* TypPracownika() const;

    friend std::ostream& operator<<(std::ostream& wy, const Kierownik& k);
    friend std::istream& operator>>(std::istream& we, Kierownik& k);
};
    