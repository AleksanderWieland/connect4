// connect4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<array>

static std::array<std::array<char, 21>, 6> gameArray()
{
    std::array<std::array<char, 21>, 6> table;
    for (int row = 0; row <= 5; row++)
    {
        for (int column = 0; column <= 20; column++)
        {
            if (column == 0) {
                table[row][column] = '[';
            }
            else if ((column - 1) % 3 == 0) {
                table[row][column] = ' ';
            }
            else if ((column + 1) % 3 == 0) {
                table[row][column] = ']';
            }
            else if (column % 3 == 0) {
                table[row][column] = '[';
            }
        }
    }
    return table;
}

void showGameArray(std::array<std::array<char, 21>, 6> inputArray)
{
    for (int row = 0; row <= 5; row++)
    {
        for (int column = 0; column <= 20; column++)
        {
            std::cout << inputArray[row][column];
        }
        std::cout << "\n";
    }
}

int main()
{
    std::cout << "Program - gra Connect Four\n";

    std::array<std::array<char, 21>, 6> newGameArray;
    newGameArray = gameArray();
    showGameArray(newGameArray);
    std::cout << "Wybierz pozycje, w ktorej chesz wrzucic zeton (od 1 do 7)\n";
    int tokenPosition;
    std::cin >> tokenPosition;


    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
