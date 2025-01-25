#include "ListaPracownikow.h"
#include <iostream>

ListaPracownikow::ListaPracownikow() {
    m_pPoczatek = nullptr;
    m_nLiczbaPracownikow = 0;
}

// Destruktor zwalniaj¹cy pamiêæ
ListaPracownikow::~ListaPracownikow()
{
    Pracownik* usun = m_pPoczatek; // Zaczyna od pierwszego elementu
    while (usun != nullptr)        // Dopóki lista nie jest pusta
    {
        Pracownik* next = usun->m_pNastepny; // Zapamiêtuje wskaŸnik na nastêpny element
        delete usun;                         // Usuwa bie¿¹cy element
        m_nLiczbaPracownikow--;              // Zmniejsza licznik pracowników
        usun = next;                         // Przechodzi do kolejnego elementu
    }
}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
    bool wasFoundInList = false;
    Pracownik* test = m_pPoczatek;

    // Sprawdza, czy pracownik ju¿ istnieje w liœcie
    while (test != nullptr)
    {
        if (test->Porownaj(p) == 0) // Jeœli pracownik istnieje, ustawia flagê
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Jeœli pracownika nie ma na liœcie, dodaje go
    if (!wasFoundInList)
    {
        Pracownik* nowy = new Pracownik(p); // Tworzy nowego pracownika
        nowy->m_pNastepny = nullptr;       // Ustawia `nullptr` jako nastêpny element
        nowy->m_pPoprzedni = nullptr;       // Ustawia `nullptr` jako poprzedni element
        if (m_nLiczbaPracownikow == 0)     // Jeœli lista jest pusta
        {
            m_pPoczatek = nowy;            // Nowy element staje siê pocz¹tkiem
        }
        else
        {
            Pracownik* last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) // Znajduje ostatni element listy
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = nowy;     // Dodaje nowy element na koñcu
            nowy->m_pPoprzedni = last;     // £¹czy wstecz z poprzednim elementem
        }
        m_nLiczbaPracownikow++;           // Zwiêksza liczbê pracowników
    }
}


void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez ca³¹ listê
    {
        if (test->Porownaj(wzorzec) == 0) // Szuka pracownika do usuniêcia
        {
            Pracownik* next = test->m_pNastepny;
            Pracownik* prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; // Jeœli to pierwszy element, przesuwa pocz¹tek
            if (prev)
                prev->m_pNastepny = next; // £¹czy poprzedni element z nastêpnym
            if (next)
                next->m_pPoprzedni = prev; // £¹czy nastêpny element z poprzednim
            m_nLiczbaPracownikow--;       // Zmniejsza licznik pracowników
            delete test;                  // Usuwa bie¿¹cy element
            break;
        }
        test = test->m_pNastepny; // Przechodzi do kolejnego elementu
    }
}

void ListaPracownikow::WypiszPracownikow() const
{
    if (m_pPoczatek == nullptr) // Jeœli lista jest pusta
    {
        std::cout << "Brak pracownikow w liscie." << std::endl;
        return;
    }

    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez listê
    {
        test->Wypisz();           // Wyœwietla dane pracownika
        std::cout << std::endl;
        test = test->m_pNastepny;    // Przechodzi do nastêpnego elementu
    }
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez listê
    {
        if (test->SprawdzNazwisko(nazwisko) == 0 && test->SprawdzImie(imie) == 0)
        {
            return test; // Zwraca znalezionego pracownika
        }

        test = test->m_pNastepny; // Przechodzi do nastêpnego elementu
    }

    return nullptr; // Taki pracownik nie istnieje
}
