#include "Kierownik.h"
#include <iostream>

using namespace std;

// Konstruktor domy�lny
Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok,
    const char* nazwaDzialu, int liczbaPracownikow)
    : Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(nazwaDzialu), m_nLiczbaPracownikow(liczbaPracownikow) {}

// Konstruktor kopiuj�cy
Kierownik::Kierownik(const Kierownik& wzor)
    : Pracownik(wzor), m_NazwaDzialu(wzor.m_NazwaDzialu), m_nLiczbaPracownikow(wzor.m_nLiczbaPracownikow) {}

// Operator przypisania
Kierownik& Kierownik::operator=(const Kierownik& wzor) {
    if (this != &wzor) {
        Pracownik::operator=(wzor);
        m_NazwaDzialu = wzor.m_NazwaDzialu;
        m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
    }
    return *this;
}

// Operator por�wnania
bool Kierownik::operator==(const Kierownik& wzor) const {
    return Pracownik::operator==(wzor) &&
        m_NazwaDzialu == wzor.m_NazwaDzialu &&
        m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow;
}

void Kierownik::WypiszDane() const
{
    cout << "ID: " << ID() << " - Kierownik: ";
    Wypisz();
    std::cout << "Dzial: " << m_NazwaDzialu.Zwroc() << ", Liczba pracownikow: " << m_nLiczbaPracownikow << endl;
}
// Wirtualna metoda KopiaObiektu
Pracownik* Kierownik::KopiaObiektu() const {
    return new Kierownik(*this);
}

// Operator strumieniowy wyj�cia
std::ostream& operator<<(std::ostream& wy, const Kierownik& k) {
    wy << k.Imie() << " " << k.Nazwisko() << " "
        << k.DzienUrodzenia() << "-" << k.MiesiacUrodzenia() << "-" << k.RokUrodzenia() << " "
        << k.m_NazwaDzialu << " " << k.m_nLiczbaPracownikow;
    return wy;
}


// Operator strumieniowy wej�cia
std::istream& operator>>(std::istream& we, Kierownik& k) {
    we >> static_cast<Pracownik&>(k); // Wczytanie cz�ci bazowej
    cout << "Podaj nazwe dzialu: ";
    we >> k.m_NazwaDzialu;
    cout << "Podaj liczbe pracownikow: ";
    we >> k.m_nLiczbaPracownikow;
    return we;
}
