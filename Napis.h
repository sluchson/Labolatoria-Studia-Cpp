#pragma once

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
};
