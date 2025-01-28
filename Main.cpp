#include <iostream>
#include "ListaPracownikow.h"
#include "Kierownik.h"
#include "Informatyk.h"

void Interfejs() {
    ListaPracownikow lista;
    const char* nazwaPliku = "lista_pracownikow.txt"; 
    int opcja;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Wprowadzanie nowego pracownika\n";
        std::cout << "2. Wprowadzanie nowego kierownika\n";
        std::cout << "3. Wprowadzanie nowego informatyka\n";
        std::cout << "4. Usuwanie pracownika\n";
        std::cout << "5. Wypisywanie calej listy\n";
        std::cout << "6. Przeszukiwanie listy\n";
        std::cout << "7. Zapisz liste do pliku\n";
        std::cout << "8. Wczytaj liste z pliku\n";
        std::cout << "9. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;
        std::cin.ignore(); // Czyszczenie bufora wejœciowego

        switch (opcja) {
        case 1: {
            std::cout << std::endl;
            Pracownik* pracownik = new Pracownik();
            pracownik->Wpisz();
            lista.Dodaj(pracownik);
            std::cout << "\nPracownik dodany!\n";
            break;
        }
        case 2: {
            std::cout << std::endl;
            Kierownik* kierownik = new Kierownik();
            kierownik->Wpisz();
            lista.Dodaj(kierownik);
            std::cout << "Kierownik dodany!\n";
            break;
        }
        case 3: {
            std::cout << std::endl;
            Informatyk* informatyk = new Informatyk();
            informatyk->Wpisz();
            lista.Dodaj(informatyk);
            std::cout << "Informatyk dodany.\n";
            break;
        }
        case 4: {
            std::cout << std::endl;
            Pracownik wzorzec;
            std::cout << "Wprowadz dane pracownika do usuniecia:\n";
            wzorzec.Wpisz(); // Wczytanie danych pracownika
            lista.Usun(wzorzec); // Usuniêcie pracownika z listy
            std::cout << "Pracownik usuniety (o ile zostaly wprowadzone poprawne dane).\n";
            break;
        }
        case 5:
            std::cout << std::endl;
            std::cout << "Lista pracownikow:\n";
            lista.WypiszPracownikow();
            break;
        case 6: {
            std::cout << std::endl;
            char imie[256], nazwisko[256];
            std::cout << "Podaj nazwisko: ";
            std::cin.getline(nazwisko, 256);
            std::cout << "Podaj imie: ";
            std::cin.getline(imie, 256);

            const Pracownik* znaleziony = lista.Szukaj(nazwisko, imie);
            if (znaleziony != nullptr) {
                std::cout << "Znaleziony pracownik:\n";
                znaleziony->WypiszDane();
            }
            else {
                std::cout << "Nie znaleziono pracownika.\n";
            }
            break;
        }
        case 7:
            std::cout << std::endl;
            lista.ZapiszDoPliku(nazwaPliku);
            break;
        case 8:
            std::cout << std::endl;
            lista.OdczytZPliku(nazwaPliku);
            break;
        case 9:
            std::cout << std::endl;
            std::cout << "Koniec programu.\n";
            break;
        default:
            std::cout << std::endl;
            std::cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }
    } while (opcja != 9);
}

int main() {
    Interfejs();
    return 0;
}
