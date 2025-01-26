#include "Data.h"
#include <iostream>

using namespace std;


Data::Data(int d, int m, int r) : m_nDzien(d), m_nMiesiac(m), m_nRok(r) {
	Koryguj();
}

Data::Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
    m_nDzien = d;
    m_nMiesiac = m;
    m_nRok = r;
	Koryguj();
}


int Data::Dzien() const
{
    return m_nDzien;
}


int Data::Miesiac() const
{
    return m_nMiesiac;
}


int Data::Rok() const
{
    return m_nRok;
}


void Data::Wypisz() const
{
    cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;
}


void Data::Wpisz()
{
	cout << "Podaj date(dd mm rrrr):";
    cin >> m_nDzien >> m_nMiesiac >> m_nRok;
	Koryguj();
}


void Data::Koryguj()
{
	//Sprawdzanie miesiaca
	if (m_nMiesiac < 1) {
		m_nMiesiac = 1;
	}
	else if (m_nMiesiac > 12) {
		m_nMiesiac = 12;
	}

	//Ustalanie liczby dni w danym miesiacu
	int dniWMiesiacu = 31;
	switch (m_nMiesiac) {
	case 4: case 6: case 9: case 11:
		dniWMiesiacu = 30;
		break;
	case 2:
		if ((m_nRok % 4 == 0 && m_nRok % 100 != 0) || m_nRok % 400 == 0) {
			dniWMiesiacu = 29;
		}
		else {
			dniWMiesiacu = 28;
		}
		break;
	}

	//Sprawdzanie dnia
	if (m_nDzien < 1) {
		m_nDzien = 1;
	}
	else if (m_nDzien > dniWMiesiacu) {
		m_nDzien = dniWMiesiacu;
	}
}


int Data::Porownaj(const Data& wzor) const
{
	if (wzor.Rok() == m_nRok && wzor.Miesiac() == m_nMiesiac && wzor.Dzien() == m_nDzien) {
		return 0;
	}
	if (wzor.Rok() > m_nRok) {
		return 1;
	}
	if (wzor.Miesiac() > m_nMiesiac) {
		return 1;
	}
	if (wzor.Dzien() > m_nDzien) {
		return 1;
	}
    return -1;
}

std::ostream& operator<<(std::ostream& wy, const Data& d)
{
	return wy << d.m_nDzien << '-' << d.m_nMiesiac << '-' << d.m_nRok;
}

std::istream& operator>>(std::istream& we, Data& d)
{
	int dd, mm, rr;
	we >> dd;
	we.ignore(1, '-');
	we >> mm;
	we.ignore(1, '-');
	we >> rr;
	d.Ustaw(dd, mm, rr);
	return we;
}