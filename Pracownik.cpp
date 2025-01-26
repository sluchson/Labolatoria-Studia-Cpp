#include "Pracownik.h"
#include "Data.h"
#include <iostream>

using namespace std;


int Pracownik::s_nastepneID = 0;

int Pracownik::ID() const { return m_nIDZatrudnienia; }
//Domyslny
Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) : 
    m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia(s_nastepneID++), m_pNastepny(nullptr), m_pPoprzedni(nullptr) {}

//Kopiujacy
Pracownik::Pracownik(const Pracownik& wzor) 
    : m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia), m_nIDZatrudnienia(s_nastepneID), m_pNastepny(nullptr), m_pPoprzedni(nullptr) {}

// Operator przypisania
Pracownik& Pracownik::operator=(const Pracownik& wzor) {
    if (this != &wzor) { // Unikanie samoprzydzia³u
        m_Imie = wzor.m_Imie;
        m_Nazwisko = wzor.m_Nazwisko;
        m_DataUrodzenia = wzor.m_DataUrodzenia;
    }
    return *this;
}

const char* Pracownik::Imie() const
{
    return m_Imie.Zwroc();
}


const char* Pracownik::Nazwisko() const
{
    return m_Nazwisko.Zwroc();
}

int Pracownik::DzienUrodzenia() const { return m_DataUrodzenia.Dzien(); }
int Pracownik::MiesiacUrodzenia() const { return m_DataUrodzenia.Miesiac(); }
int Pracownik::RokUrodzenia() const { return m_DataUrodzenia.Rok(); }
void Pracownik::WypiszDateUrodzenia() const { m_DataUrodzenia.Wypisz(); }

void Pracownik::Imie(const char* nowe_imie)
{
    m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
    m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
    m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const 
{   

    m_Imie.Wypisz();
    cout << " ";
    m_Nazwisko.Wypisz();
    cout << " ";
    m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
    cout << "Podaj imie: ";
    m_Imie.Wpisz();
    cout << "Podaj nazwisko: ";
    m_Nazwisko.Wpisz();
    m_DataUrodzenia.Wpisz();
    cin.ignore();
}

int Pracownik::SprawdzImie(const char* por_imie) const 
{
    return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const 
{
    return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const 
{
    int por = SprawdzNazwisko(wzorzec.Nazwisko());
    if (por != 0)
        return por;
    por = SprawdzImie(wzorzec.Imie());
    if (por != 0)
        return por;

    return m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);

}

bool Pracownik::operator==(const Pracownik& wzor) const
{
    return m_Imie == wzor.m_Imie && m_Nazwisko == wzor.m_Nazwisko && m_DataUrodzenia.Porownaj(wzor.m_DataUrodzenia) == 0;
}

void Pracownik::WypiszDane() const
{
    cout << "ID: " << m_nIDZatrudnienia << " - Pracownik: ";
    Wypisz();
}

Pracownik* Pracownik::KopiaObiektu() const
{
    return new Pracownik(*this);
}

// Wirtualny destruktor
Pracownik::~Pracownik() {}

std::ostream& operator<<(std::ostream& wy, const Pracownik& p)
{
    return wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
}

std::istream& operator>>(std::istream& we, Pracownik& p) 
{
    we >> p.m_Imie;
    we >> p.m_Nazwisko;
    we >> p.m_DataUrodzenia;
    we.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return we;
}