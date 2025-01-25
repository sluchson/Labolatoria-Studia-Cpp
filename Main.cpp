#include <iostream>
#include "ListaPracownikow.h"

void Interfejs() {
    ListaPracownikow lista;
    int opcja;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Wprowadzanie nowego pracownika\n";
        std::cout << "2. Usuwanie pracownika\n";
        std::cout << "3. Wypisywanie calej listy\n";
        std::cout << "4. Przeszukiwanie listy\n";
        std::cout << "5. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;
        std::cin.ignore(); // Czyszczenie bufora wejœcia

        switch (opcja) {
        case 1: {
            char imie[256], nazwisko[256];
            int dzien, miesiac, rok;
            std::cout << "Podaj imie: ";
            std::cin.getline(imie, 256);
            std::cout << "Podaj nazwisko: ";
            std::cin.getline(nazwisko, 256);
            std::cout << "Podaj date urodzenia (dzien miesiac rok): ";
            std::cin >> dzien >> miesiac >> rok;
            std::cin.ignore();

            Pracownik nowy(imie, nazwisko, dzien, miesiac, rok);
            lista.Dodaj(nowy);
            std::cout << "Pracownik dodany.\n";
            break;
        }
        case 2: {
            /*char imie[256], nazwisko[256];
            std::cout << "Podaj imie pracownika do usuniecia: ";
            std::cin.getline(imie, 256);
            std::cout << "Podaj nazwisko pracownika do usuniecia: ";
            std::cin.getline(nazwisko, 256);

            Pracownik doUsuniecia(imie, nazwisko);
            lista.Usun(doUsuniecia);
            std::cout << "Pracownik usuniety (jesli istnial).\n";*/
            Pracownik wzorzec;
            std::cout << "Wprowadz dane pracownika do usuniecia:\n";
            wzorzec.Wpisz(); // Wczytanie danych pracownika
            lista.Usun(wzorzec); // Usuniêcie pracownika z listy
            std::cout << "Pracownik usuniety (o ile zostaly wprowadzone poprawne dane).\n";
            break;
        }
        case 3:
            std::cout << "Lista pracownikow:\n";
            lista.WypiszPracownikow();
            break;
        case 4: {
            char imie[256], nazwisko[256];
            std::cout << "Podaj nazwisko: ";
            std::cin.getline(nazwisko, 256);
            std::cout << "Podaj imie: ";
            std::cin.getline(imie, 256);

            const Pracownik* znaleziony = lista.Szukaj(nazwisko, imie);
            if (znaleziony != nullptr) {
                std::cout << "Znaleziony pracownik:\n";
                znaleziony->Wypisz();
            }
            else {
                std::cout << "Nie znaleziono pracownika.\n";
            }
            break;
        }
        case 5:
            std::cout << "Koniec programu.\n";
            break;
        default:
            std::cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }
    } while (opcja != 5);
}

int main() {
    Interfejs();
    return 0;
}
