#include "Informatyk.h"
#include <iostream>

using namespace std;

// Konstruktor domyœlny
Informatyk::Informatyk(const char* im, const char* naz, int dzien, int miesiac, int rok,
    const char* aplikacja, int liczbaAplikacji)
    : Pracownik(im, naz, dzien, miesiac, rok), m_TworzonaAplikacja(aplikacja), m_nLiczbaAplikacji(liczbaAplikacji) {}

// Konstruktor kopiuj¹cy
Informatyk::Informatyk(const Informatyk& wzor)
    : Pracownik(wzor), m_TworzonaAplikacja(wzor.m_TworzonaAplikacja), m_nLiczbaAplikacji(wzor.m_nLiczbaAplikacji) {}

// Operator przypisania
Informatyk& Informatyk::operator=(const Informatyk& wzor) {
    if (this != &wzor) {
        Pracownik::operator=(wzor);
        m_TworzonaAplikacja = wzor.m_TworzonaAplikacja;
        m_nLiczbaAplikacji = wzor.m_nLiczbaAplikacji;
    }
    return *this;
}

// Operator porównania
bool Informatyk::operator==(const Informatyk& wzor) const {
    return Pracownik::operator==(wzor) &&
        m_TworzonaAplikacja == wzor.m_TworzonaAplikacja &&
        m_nLiczbaAplikacji == wzor.m_nLiczbaAplikacji;
}

// Wypisanie danych
void Informatyk::WypiszDane() const {
    std::cout << "Informatyk: ";
    Wypisz();
    cout << "Tworzona aplikacja: " << m_TworzonaAplikacja.Zwroc() << ", Liczba aplikacji: " << m_nLiczbaAplikacji << endl;
}

// Kopia obiektu
Pracownik* Informatyk::KopiaObiektu() const {
    return new Informatyk(*this);
}

// Wstawianie do strumienia
ostream& operator<<(ostream& wy, const Informatyk& i) {
    wy << i.Imie() << " " << i.Nazwisko() << " " 
        << i.DzienUrodzenia() << "-" << i.MiesiacUrodzenia() << "-" << i.RokUrodzenia() << " " 
        << i.m_TworzonaAplikacja << " " << i.m_nLiczbaAplikacji;
    return wy;
}


// Operator strumieniowy wejœcia
std::istream& operator>>(std::istream& we, Informatyk& i) {
    we >> static_cast<Informatyk&>(i); // Wczytanie czêœci bazowej
    cout << "Podaj nazwe tworzonej aplikacji przez pracownika: ";
    we >> i.m_TworzonaAplikacja;
    cout << "Podaj liczbe utworzonych aplikacji przez pracownika: ";
    we >> i.m_nLiczbaAplikacji;
    return we;
}