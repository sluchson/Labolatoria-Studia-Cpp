#include "Napis.h"
#include <iostream>
#include <string.h>


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

Napis::Napis(const Napis& wzor) 
{
    m_nDl = wzor.m_nDl;
    m_pszNapis = new char[m_nDl];
    strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
}

Napis::~Napis() {
    delete[] m_pszNapis;
}

const char* Napis::Zwroc() const {
    return m_pszNapis;
}

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

void Napis::Wypisz() const {
    std::cout << m_pszNapis;
}

void Napis::Wpisz() {
    char bufor[256];
    std::cin.getline(bufor, 256);
    Ustaw(bufor);
}

int Napis::SprawdzNapis(const char* por_napis) const
{
    return strcmp(m_pszNapis, por_napis);
}

Napis& Napis::operator=(const Napis& wzor) {
    if (this != &wzor) { // Unikamy samoprzypisania
        delete[] m_pszNapis; 
        m_nDl = wzor.m_nDl;
        m_pszNapis = new char[m_nDl];
        strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
    }
    return *this;
}

bool Napis::operator==(const Napis& wzor) const
{
    if (strcmp(m_pszNapis, wzor.Zwroc()) == 0)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& wy, const Napis& p) {
    return wy << p.m_pszNapis;
}

std::istream& operator>>(std::istream& we, Napis& p) {
    char pom[40];

    memset(pom, 0, sizeof(pom));

    while (we.peek() == ' ')
    {
        we.ignore();
    }

    int i = 0;
    while (we && we.peek() != '\n' && i <= 40)
    {
        char c = we.get();
        if (c != ' ') 
        {
            pom[i++] = c;
        }
    }

    p.Ustaw(pom);
    we.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return we;
}
