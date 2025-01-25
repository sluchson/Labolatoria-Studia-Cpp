#pragma once

class Napis
{
    char* m_pszNapis; // Wska�nik na napis
    int m_nDl;        // D�ugo�� napisu
public:
    Napis(const char* nap = ""); // Konstruktor domy�lny
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
