#pragma once
#include <iostream>


class Napis
{
    char* m_pszNapis; // WskaŸnik na napis
    int m_nDl;        // D³ugoœæ napisu
public:
    Napis(const char* nap = ""); // Konstruktor domyœlny
    Napis(const Napis& wzor);
    ~Napis();                    // Destruktor
    const char* Zwroc() const;
    void Ustaw(const char* nowy_napis);
    void Wypisz() const;
    void Wpisz();
    int SprawdzNapis(const char* por_napis) const;
    // Operator przypisania
    Napis& operator=(const Napis& wzor);

    bool operator==(const Napis& wzor) const;

    friend std::ostream& operator<<(std::ostream& wy, const Napis& p);
    friend std::istream& operator>>(std::istream& we, Napis& p);
};

std::ostream& operator<<(std::ostream& wy, const Napis& p);
std::istream& operator>>(std::istream& we, Napis& p);