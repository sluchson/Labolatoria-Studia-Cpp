#include "Kierownik.h"
#include <iostream>

using namespace std;


Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* nazwaDzialu, int liczbaPracownikow)
    : Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(nazwaDzialu), m_nLiczbaPracownikow(liczbaPracownikow) {}

Kierownik::Kierownik(const Kierownik& wzor)
    : Pracownik(wzor), m_NazwaDzialu(wzor.m_NazwaDzialu), m_nLiczbaPracownikow(wzor.m_nLiczbaPracownikow) {}

Kierownik& Kierownik::operator=(const Kierownik& wzor) {
    if (this != &wzor) {
        Pracownik::operator=(wzor);
        m_NazwaDzialu = wzor.m_NazwaDzialu;
        m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
    }
    return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const {
    return Pracownik::operator==(wzor) &&
        m_NazwaDzialu == wzor.m_NazwaDzialu &&
        m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow;
}

const char* Kierownik::TypPracownika() const {
    return "Kierownik";
}

void Kierownik::Wpisz()
{

    Pracownik::Wpisz();
    cout << "Podaj nazwe dzialu: ";
    m_NazwaDzialu.Wpisz();
    cout << "Podaj liczbe pracownikow: ";
    cin >> m_nLiczbaPracownikow;
    cin.ignore();
}

void Kierownik::WypiszDane() const {
    Pracownik::WypiszDane(); // Wywo³anie metody bazowej
    cout << "Dzial: " << m_NazwaDzialu.Zwroc()
        << ", Liczba pracownikow: " << m_nLiczbaPracownikow << endl;
}

Pracownik* Kierownik::KopiaObiektu() const {
    return new Kierownik(*this);
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& k) {
    wy << k.Imie() << " " << k.Nazwisko() << " "
        << k.DzienUrodzenia() << "-" << k.MiesiacUrodzenia() << "-" << k.RokUrodzenia() << " "
        << k.m_NazwaDzialu << " " << k.m_nLiczbaPracownikow;
    return wy;
}


std::istream& operator>>(std::istream& we, Kierownik& k) {
    we >> static_cast<Pracownik&>(k); // Wczytanie czêœci bazowej
    cout << "Podaj nazwe dzialu: ";
    we >> k.m_NazwaDzialu;
    cout << "Podaj liczbe pracownikow: ";
    we >> k.m_nLiczbaPracownikow;
    return we;
}
