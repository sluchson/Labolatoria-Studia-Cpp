#pragma once
#include "Pracownik.h"

class Informatyk : public Pracownik {
private:
    Napis m_TworzonaAplikacja; // Aktualnie tworzona aplikacja
    int m_nLiczbaAplikacji;    // Liczba stworzonych aplikacji

public:
    Informatyk(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000,
        const char* aplikacja = "", int liczbaAplikacji = 0);

    Informatyk(const Informatyk& wzor);

    Informatyk& operator=(const Informatyk& wzor);

    bool operator==(const Informatyk& wzor) const;

    void Wpisz();

    virtual void WypiszDane() const override;
    virtual const char* TypPracownika() const;

    virtual Pracownik* KopiaObiektu() const override;

    friend std::ostream& operator<<(std::ostream& wy, const Informatyk& i);

    friend std::istream& operator>>(std::istream& we, Informatyk& i);
};
