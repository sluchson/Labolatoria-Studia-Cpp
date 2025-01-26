#include "ListaPracownikow.h"
#include "Kierownik.h"
#include "Informatyk.h"

using namespace std;

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

void ListaPracownikow::Dodaj(Pracownik* p)
{
    bool wasFoundInList = false;
    Pracownik* test = m_pPoczatek;

    // Sprawdza, czy pracownik ju¿ istnieje w liœcie
    while (test != nullptr)
    {
        if (test->Porownaj(*p) == 0) // Porównanie obiektu przez referencjê
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Jeœli pracownika nie ma na liœcie, dodaje go
    if (!wasFoundInList)
    {
        Pracownik* nowy = p->KopiaObiektu(); // Tworzy nowy obiekt za pomoc¹ wirtualnej metody
        nowy->m_pNastepny = nullptr;       // Ustawia `nullptr` jako nastêpny element
        nowy->m_pPoprzedni = nullptr;      // Ustawia `nullptr` jako poprzedni element
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
            nowy->m_pPoprzedni = last;   // £¹czy wstecz z poprzednim elementem
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
        test->WypiszDane();        // Wywo³uje wirtualn¹ metodê `WypiszDane`
        std::cout << std::endl;
        test = test->m_pNastepny;  // Przechodzi do nastêpnego elementu
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

void ListaPracownikow::ZapiszDoPliku(const char* nazwaPliku) const
{
    std::ofstream plik(nazwaPliku);
    if (plik.is_open())
    {
        Pracownik* p = m_pPoczatek;
        while (p != nullptr)
        {
            // SprawdŸ typ obiektu i zapisz z odpowiednim identyfikatorem
            if (dynamic_cast<Kierownik*>(p) != nullptr) {
                plik << "K " << *dynamic_cast<Kierownik*>(p) << "\n"; // Kierownik
            }
            else if (dynamic_cast<Informatyk*>(p) != nullptr) {
                plik << "I " << *dynamic_cast<Informatyk*>(p) << "\n"; // Informatyk
            }
            else {
                plik << "P " << *p << "\n"; // Pracownik
            }
            p = p->m_pNastepny;
        }
        plik.close();
        std::cout << "Pomyslnie zapisano liste pracownikow do pliku\n";
    }
    else
    {
        std::cerr << "Nie udalo sie otworzyc pliku " << nazwaPliku << std::endl;
    }
}


void ListaPracownikow::OdczytZPliku(const char* nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do odczytu: " << nazwaPliku << std::endl;
        return;
    }

    char typ;
    while (plik >> typ) { // Odczyt typu obiektu: 'P' lub 'K'
        if (typ == 'P') {
            char imie[256], nazwisko[256];
            int dzien, miesiac, rok;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-'); // Ignoruj separator '-'
            plik >> miesiac;
            plik.ignore(1, '-'); // Ignoruj separator '-'
            plik >> rok;

            if (!plik.fail()) {
                Pracownik* nowyPracownik = new Pracownik(imie, nazwisko, dzien, miesiac, rok);
                Dodaj(nowyPracownik);
            }
        }
        else if (typ == 'K') {
            char imie[256], nazwisko[256], nazwaDzialu[256];
            int dzien, miesiac, rok, liczbaPracownikow;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-'); // Ignoruj separator '-'
            plik >> miesiac;
            plik.ignore(1, '-'); // Ignoruj separator '-'
            plik >> rok;
            plik >> nazwaDzialu >> liczbaPracownikow;

            if (!plik.fail()) {
                Kierownik* nowyKierownik = new Kierownik(imie, nazwisko, dzien, miesiac, rok, nazwaDzialu, liczbaPracownikow);
                Dodaj(nowyKierownik);
            }
        }
    }

    plik.close();
    std::cout << "Lista pracownikow zostala odczytana z pliku " << nazwaPliku << std::endl;
}






