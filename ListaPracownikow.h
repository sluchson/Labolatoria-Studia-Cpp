#pragma once
#include "Pracownik.h"

#include<fstream>
#include <iostream>
#include <cstring>

class ListaPracownikow
{
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
public:
	ListaPracownikow();
	~ListaPracownikow();
	void Dodaj(Pracownik* p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	void ZapiszDoPliku(const char* nazwaPliku) const;
	void OdczytZPliku(const char* nazwaPliku);
};

