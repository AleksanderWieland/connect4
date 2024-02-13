// connect4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<array>

static std::array<std::array<char, 21>, 6> createGameArray()
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
                table[row][column] = '_';
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

int convertInputTokenPositionIntoPositionInGameArray(int tokenPositionInput)
{
    if (tokenPositionInput == 1)
    {
        return 1;
    }
    else
    return (tokenPositionInput - 1) * 2 + tokenPositionInput;
}

static std::array<std::array<char, 21>, 6> returnGameArrayWithTokenAdded(std::array<std::array<char, 21>, 6> inputArray, int tokenPosition, int numberOfTurns)
{
    std::array<std::array<char, 21>, 6> table;
    table = inputArray;
    for (int row = 5; row >= 0; row--)
    {
        if (table[row][tokenPosition] == '_')
        {
            if (numberOfTurns % 2 == 0) {
                table[row][tokenPosition] = 'O';
            }
            else
            {
                table[row][tokenPosition] = 'X';
            }
            break;
        }
    }
    return table;
}


int main()
{
    std::cout << "Program - gra Connect Four\n";

    std::array<std::array<char, 21>, 6> newGameArray;
    newGameArray = createGameArray();
    showGameArray(newGameArray);
    int numberOfTurns = 0;
    int tokenPosition;

    while (1)
    {
        std::cout << "Wybierz pozycje, w ktorej chesz wrzucic zeton (od 1 do 7)\n";
        std::cin >> tokenPosition;
        tokenPosition = convertInputTokenPositionIntoPositionInGameArray(tokenPosition);
        newGameArray = returnGameArrayWithTokenAdded(newGameArray, tokenPosition, numberOfTurns);
        showGameArray(newGameArray);
        numberOfTurns++;

        for (int row = 0; row <= 5; row++)
        {
            //aby nie brało pod uwagę żetonów w dwóch kolejnych rzędach
            char lastFoundToken = '!';
            int numberOfConnectedTokens = 1;

            for (int column = 1; column <= 7; column++)
            {
                int convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
                if (newGameArray[row][convertedColumn] != '_')
                {
                    //std::cout << (convertedColumn) << "\n";
                    if (lastFoundToken != newGameArray[row][convertedColumn])
                    {
                        
                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[row][convertedColumn];
                    }
                    else
                    {
                        numberOfConnectedTokens++;
                    }
                    if (numberOfConnectedTokens == 4)
                    {
                      //  std::cout << "Wygral zawodnik uzywajacy zetonow " << lastFoundToken << " !";
                        system("pause");
                        return 0;

                    }
                }
                else {
                    numberOfConnectedTokens = 1;
                }
            }
        }


        for (int column = 1; column <= 7; column++)
        {
            int convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
            //aby nie brało pod uwagę żetonów w dwóch kolejnych kolumnach
            char lastFoundToken = '!';
            int numberOfConnectedTokens = 1;

            for (int row = 0; row <= 5; row++)
            {
                if (newGameArray[row][convertedColumn] != '_')
                {
                    if (lastFoundToken != newGameArray[row][convertedColumn])
                    {

                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[row][convertedColumn];
                     //   std::cout << lastFoundToken << " inny" << "\n";
                    }
                    else
                    {
                        numberOfConnectedTokens++;
                     //   std::cout << numberOfConnectedTokens << "\n";
                      //  std::cout << lastFoundToken << " ten sam" << "\n";
                    }
                    if (numberOfConnectedTokens == 4)
                    {
                      //  std::cout << "Wygral zawodnik uzywajacy zetonow " << lastFoundToken << " !";
                        system("pause");
                        return 0;
                    }
                }
                else {
                    numberOfConnectedTokens = 1;
                }
            }
        }

        for (int column = 1; column <= 4; column++)
        {
            int convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
            //aby nie brało pod uwagę żetonów w dwóch kolejnych kolumnach
            char lastFoundToken = '!';
            int numberOfConnectedTokens = 1;
            int iterator = 0;

            for (int row = 2; row <= 5; row++)
            {
                while((row + iterator) <= 5 && (convertedColumn + iterator) <= 7)
                {
                   // std::cout << row - iterator;
                    int newRow = row + iterator;
                    int newColumn = convertedColumn + iterator * 3;
                    if (newGameArray[newRow][newColumn] != '_')
                    {
                        if (lastFoundToken != newGameArray[newRow][newColumn])
                        {

                            numberOfConnectedTokens = 1;
                            lastFoundToken = newGameArray[newRow][newColumn];
                          //  std::cout << lastFoundToken << " inny" << "\n";
                        }
                        else
                        {
                            numberOfConnectedTokens++;
                           // std::cout << numberOfConnectedTokens << "\n";
                           // std::cout << lastFoundToken << " ten sam" << "\n";
                        }
                        if (numberOfConnectedTokens == 4)
                        {
                         //   std::cout << "Wygral zawodnik uzywajacy zetonow " << lastFoundToken << " !";
                            system("pause");
                            return 0;
                        }
                    }
                    else {
                        numberOfConnectedTokens = 1;
                    }
                   iterator++;
                }
                iterator = 1;
            }
        }

    }
    system("pause");
    return 0;
}