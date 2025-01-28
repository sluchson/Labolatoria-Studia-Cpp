#include "Informatyk.h"
#include <iostream>

using namespace std;

Informatyk::Informatyk(const char* im, const char* naz, int dzien, int miesiac, int rok,
    const char* aplikacja, int liczbaAplikacji)
    : Pracownik(im, naz, dzien, miesiac, rok), m_TworzonaAplikacja(aplikacja), m_nLiczbaAplikacji(liczbaAplikacji) {}

Informatyk::Informatyk(const Informatyk& wzor)
    : Pracownik(wzor), m_TworzonaAplikacja(wzor.m_TworzonaAplikacja), m_nLiczbaAplikacji(wzor.m_nLiczbaAplikacji) {}

Informatyk& Informatyk::operator=(const Informatyk& wzor) {
    if (this != &wzor) {
        Pracownik::operator=(wzor);
        m_TworzonaAplikacja = wzor.m_TworzonaAplikacja;
        m_nLiczbaAplikacji = wzor.m_nLiczbaAplikacji;
    }
    return *this;
}

bool Informatyk::operator==(const Informatyk& wzor) const {
    return Pracownik::operator==(wzor) &&
        m_TworzonaAplikacja == wzor.m_TworzonaAplikacja &&
        m_nLiczbaAplikacji == wzor.m_nLiczbaAplikacji;
}

const char* Informatyk::TypPracownika() const {
    return "Informatyk";
}

void Informatyk::Wpisz()
{

    Pracownik::Wpisz();
    cout << "Podaj nazwe tworzonej aplikacji: ";
    m_TworzonaAplikacja.Wpisz();
    cout << "Podaj liczbe utworzonych aplikacji: ";
    cin >> m_nLiczbaAplikacji;
    cin.ignore();
}

void Informatyk::WypiszDane() const {
    Pracownik::WypiszDane(); // Wywo³anie metody bazowej
    cout << "Tworzona aplikacja: " << m_TworzonaAplikacja.Zwroc()
        << ", Liczba aplikacji: " << m_nLiczbaAplikacji << endl;
}

Pracownik* Informatyk::KopiaObiektu() const {
    return new Informatyk(*this);
}

ostream& operator<<(ostream& wy, const Informatyk& i) {
    wy << i.Imie() << " " << i.Nazwisko() << " " << i.DzienUrodzenia() << "-" << i.MiesiacUrodzenia() << "-" << i.RokUrodzenia() << " " 
        << i.m_TworzonaAplikacja << " " << i.m_nLiczbaAplikacji;
    return wy;
}

std::istream& operator>>(std::istream& we, Informatyk& i) {
    we >> static_cast<Pracownik&>(i); // Wczytanie czêœci bazowej
    cout << "Podaj nazwe tworzonej aplikacji: ";
    we >> i.m_TworzonaAplikacja;
    cout << "Podaj liczbe utworzonych aplikacji: ";
    we >> i.m_nLiczbaAplikacji;
    return we;
}