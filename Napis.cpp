#include "Napis.h"
#include <iostream>
#include <string.h>

using namespace std;

// Konstruktor domyœlny
Napis::Napis(const char* nap) {
    if (nap) {
        m_nDl = strlen(nap) + 1;  // D³ugoœæ napisu (+1 dla '\0')
        m_pszNapis = new char[m_nDl];
        strcpy_s(m_pszNapis, m_nDl, nap);
    }
    else {
        m_nDl = 1;
        m_pszNapis = new char[m_nDl];
        m_pszNapis[0] = '\0';
    }
}

// Konstruktor kopiuj¹cy
Napis::Napis(const Napis& wzor) {
    m_nDl = wzor.m_nDl;
    m_pszNapis = new char[m_nDl];
    strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
}

// Destruktor
Napis::~Napis() {
    delete[] m_pszNapis;
}

// Operator przypisania
Napis& Napis::operator=(const Napis& wzor) {
    if (this != &wzor) { // Unikamy samoprzypisania
        delete[] m_pszNapis; // Zwolnij wczesniej przydzielona pamiec
        m_nDl = wzor.m_nDl;
        m_pszNapis = new char[m_nDl];
        strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
    }
    return *this;
}

// Metoda zwracaj¹ca napis
const char* Napis::Zwroc() const {
    return m_pszNapis;
}

// Metoda ustawiaj¹ca nowy napis
void Napis::Ustaw(const char* nowy_napis) {
    if (nowy_napis) {
        int nowaDl = strlen(nowy_napis) + 1;
        if (nowaDl > m_nDl) {
            delete[] m_pszNapis; 
            m_pszNapis = new char[nowaDl];
            m_nDl = nowaDl;
        }
        strcpy_s(m_pszNapis, m_nDl, nowy_napis);
    }
    else {
        m_pszNapis[0] = '\0'; 
    }
}

// Metoda wypisuj¹ca napis
void Napis::Wypisz() const {
    cout << m_pszNapis;
}

// Metoda wczytuj¹ca napis
void Napis::Wpisz() {
    char bufor[256];
    cin.getline(bufor, 256);
    Ustaw(bufor);
}

// Porównanie napisu
int Napis::SprawdzNapis(const char* por_napis) const {
    return strcmp(m_pszNapis, por_napis);
}
