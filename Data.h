#pragma once
class Data
{
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
public:
	// Konstruktor inicjalizuj�cy i koryguj�cy dat�
	Data(int d, int m, int r);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data& wzor) const;
};

