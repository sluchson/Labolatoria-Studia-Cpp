#pragma once
#include "Data.h"
#include "Napis.h"
#include <iostream>

class Pracownik
{
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int s_nastepneID; // Statyczny licznik dla unikalnych ID
public:
	Pracownik* m_pNastepny;
	Pracownik* m_pPoprzedni;


	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesi¹c = 1, int rok = 2000);
	Pracownik(const Pracownik& wzor);
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	int DzienUrodzenia() const;
	int MiesiacUrodzenia() const;
	int RokUrodzenia() const;
	void WypiszDateUrodzenia() const;

	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;
	Pracownik& operator=(const Pracownik& wzor);

	bool operator==(const Pracownik& wzor) const;


	virtual void WypiszDane() const;
	virtual Pracownik* KopiaObiektu() const;
	virtual ~Pracownik();

	friend std::ostream& operator<<(std::ostream& wy, const Pracownik& p);
	friend std::istream& operator>>(std::istream& we, Pracownik& p);
};
std::ostream& operator<<(std::ostream& wy, const Pracownik& p);
std::istream& operator>>(std::istream& we, Pracownik& p);