#include "ListaPracownikow.h"
#include "Kierownik.h"
#include "Informatyk.h"

using namespace std;

ListaPracownikow::ListaPracownikow() {
    m_pPoczatek = nullptr;
    m_nLiczbaPracownikow = 0;
}

// Destruktor zwalniaj�cy pami��
ListaPracownikow::~ListaPracownikow()
{
    Pracownik* usun = m_pPoczatek; // Zaczyna od pierwszego elementu
    while (usun != nullptr)        // Dop�ki lista nie jest pusta
    {
        Pracownik* next = usun->m_pNastepny; // Zapami�tuje wska�nik na nast�pny element
        delete usun;                         // Usuwa bie��cy element
        m_nLiczbaPracownikow--;              // Zmniejsza licznik pracownik�w
        usun = next;                         // Przechodzi do kolejnego elementu
    }
}

void ListaPracownikow::Dodaj(Pracownik* p)
{
    bool wasFoundInList = false;
    Pracownik* test = m_pPoczatek;

    // Sprawdza, czy pracownik ju� istnieje w li�cie
    while (test != nullptr)
    {
        if (test->Porownaj(*p) == 0) // Por�wnanie obiektu przez referencj�
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Je�li pracownika nie ma na li�cie, dodaje go
    if (!wasFoundInList)
    {
        Pracownik* nowy = p->KopiaObiektu(); // Tworzy nowy obiekt za pomoc� wirtualnej metody
        nowy->m_pNastepny = nullptr;       // Ustawia `nullptr` jako nast�pny element
        nowy->m_pPoprzedni = nullptr;      // Ustawia `nullptr` jako poprzedni element
        if (m_nLiczbaPracownikow == 0)     // Je�li lista jest pusta
        {
            m_pPoczatek = nowy;            // Nowy element staje si� pocz�tkiem
        }
        else
        {
            Pracownik* last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) // Znajduje ostatni element listy
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = nowy;     // Dodaje nowy element na ko�cu
            nowy->m_pPoprzedni = last;   // ��czy wstecz z poprzednim elementem
        }
        m_nLiczbaPracownikow++;           // Zwi�ksza liczb� pracownik�w
    }
}



void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez ca�� list�
    {
        if (test->Porownaj(wzorzec) == 0) // Szuka pracownika do usuni�cia
        {
            Pracownik* next = test->m_pNastepny;
            Pracownik* prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; // Je�li to pierwszy element, przesuwa pocz�tek
            if (prev)
                prev->m_pNastepny = next; // ��czy poprzedni element z nast�pnym
            if (next)
                next->m_pPoprzedni = prev; // ��czy nast�pny element z poprzednim
            m_nLiczbaPracownikow--;       // Zmniejsza licznik pracownik�w
            delete test;                  // Usuwa bie��cy element
            break;
        }
        test = test->m_pNastepny; // Przechodzi do kolejnego elementu
    }
}

void ListaPracownikow::WypiszPracownikow() const
{
    if (m_pPoczatek == nullptr) // Je�li lista jest pusta
    {
        std::cout << "Brak pracownikow w liscie." << std::endl;
        return;
    }

    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez list�
    {
        test->WypiszDane();        // Wywo�uje wirtualn� metod� `WypiszDane`
        std::cout << std::endl;
        test = test->m_pNastepny;  // Przechodzi do nast�pnego elementu
    }
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez list�
    {
        if (test->SprawdzNazwisko(nazwisko) == 0 && test->SprawdzImie(imie) == 0)
        {
            return test; // Zwraca znalezionego pracownika
        }

        test = test->m_pNastepny; // Przechodzi do nast�pnego elementu
    }

    return nullptr; // Taki pracownik nie istnieje
}

void ListaPracownikow::ZapiszDoPliku(const char* nazwaPliku) const {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie uda�o si� otworzy� pliku do zapisu: " << nazwaPliku << std::endl;
        return;
    }

    Pracownik* p = m_pPoczatek;
    while (p != nullptr) {
        if (dynamic_cast<Kierownik*>(p) != nullptr) {
            plik << "K " << p->ID() << " " << *dynamic_cast<Kierownik*>(p) << "\n";
        }
        else if (dynamic_cast<Informatyk*>(p) != nullptr) {
            plik << "I " << p->ID() << " " << *dynamic_cast<Informatyk*>(p) << "\n";
        }
        else {
            plik << "P " << p->ID() << " " << *p << "\n";
        }
        p = p->m_pNastepny;
    }

    plik.close();
    std::cout << "Pomyslnie zapisano liste pracownikow do pliku\n";
}



void ListaPracownikow::OdczytZPliku(const char* nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie uda�o si� otworzy� pliku do odczytu: " << nazwaPliku << std::endl;
        return;
    }

    char typ;
    while (plik >> typ) { // Odczyt typu obiektu: 'P', 'K', lub 'I'
        int id;
        plik >> id;

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
            plik.ignore(1, '-');
            plik >> miesiac;
            plik.ignore(1, '-');
            plik >> rok;
            plik >> nazwaDzialu >> liczbaPracownikow;

            if (!plik.fail()) {
                Kierownik* nowyKierownik = new Kierownik(imie, nazwisko, dzien, miesiac, rok, nazwaDzialu, liczbaPracownikow);
                Dodaj(nowyKierownik);
            }
        }
        else if (typ == 'I') {
            char imie[256], nazwisko[256], aplikacja[256];
            int dzien, miesiac, rok, liczbaAplikacji;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-');
            plik >> miesiac;
            plik.ignore(1, '-');
            plik >> rok;
            plik >> aplikacja >> liczbaAplikacji;

            if (!plik.fail()) {
                Informatyk* nowyInformatyk = new Informatyk(imie, nazwisko, dzien, miesiac, rok, aplikacja, liczbaAplikacji);
                Dodaj(nowyInformatyk);
            }
        }
    }

    plik.close();
    std::cout << "Lista pracownikow zostala odczytana z pliku\n";
}







