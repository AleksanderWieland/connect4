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

void winnerOutput(char winningToken)
{
    std::cout << "Wygral zawodnik uzywajacy zetonow '" << winningToken << "'!";
    system("pause");
}

int getInput(int numberOfColumns)
{
    int pickedColumn;
    while (!(std::cin >> pickedColumn) || std::cin.fail() || pickedColumn > numberOfColumns || pickedColumn < 0)
    {
       std::cin.clear();
       std::cin.ignore();
       std::cout << "Try again. The value must be between" << 0 << " and " << numberOfColumns << std::endl;
    }
    return pickedColumn;
}


int main()
{
    std::cout << "Program - gra Connect Four\n";

    std::array<std::array<char, 21>, 6> newGameArray;
    newGameArray = createGameArray();
    showGameArray(newGameArray);
    int numberOfTurns = 0;
    int tokenPosition;
    int yArrayDimentionLength = 5;
    int xArrayDimentionLength = 7;

    for (int maxPossibleTurns = (yArrayDimentionLength * xArrayDimentionLength); maxPossibleTurns >= 0; maxPossibleTurns--)
    {
        std::cout << "Wybierz pozycje, w ktorej chesz wrzucic zeton (od 1 do 7)\n";
        tokenPosition = getInput(xArrayDimentionLength);
        tokenPosition = convertInputTokenPositionIntoPositionInGameArray(tokenPosition);
        newGameArray = returnGameArrayWithTokenAdded(newGameArray, tokenPosition, numberOfTurns);
        showGameArray(newGameArray);
        numberOfTurns++;

        //poziomo
        for (int row = 0; row <= 5; row++)
        {
            char lastFoundToken = '!';
            int numberOfConnectedTokens = 1;

            for (int column = 1; column <= 7; column++)
            {
                int convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
                if (newGameArray[row][convertedColumn] != '_')
                {
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
                        winnerOutput(lastFoundToken);
                        return 0;
                    }
                }
                else
                {
                    numberOfConnectedTokens = 0;
                }

            }
            numberOfConnectedTokens = 0;
        }

        //pionowo
        int convertedColumn;
        char lastFoundToken = '!';
        int numberOfConnectedTokens = 1;
        for (int column = 1; column <= 7; column++)
        {
            convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
            lastFoundToken = '!';
            numberOfConnectedTokens = 1;

            for (int row = 0; row <= 5; row++)
            {
                if (newGameArray[row][convertedColumn] != '_')
                {
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
                        winnerOutput(lastFoundToken);
                        return 0;
                    }
                }
                else
                {
                    numberOfConnectedTokens = 0;
                }
            }
            numberOfConnectedTokens = 0;
        }

        //ukos górna część ->[/]
        lastFoundToken = '_';
        for (int row = 3; row <= yArrayDimentionLength; row++)
        {
            int iterator = 0;
            for (int column = 1; column <= row + 1; column++)
            {
                convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
                int iteratedRow = row - iterator;
                std::cout << "(" << iteratedRow << ", " << convertedColumn << "), ";
                if (newGameArray[iteratedRow][convertedColumn] != '_')
                {
                    if (newGameArray[iteratedRow][convertedColumn] == lastFoundToken)
                    {
                        numberOfConnectedTokens++;
                    }
                    else
                    {
                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[iteratedRow][convertedColumn];
                    }

                }
                else
                {
                    numberOfConnectedTokens = 0;
                }

                if (numberOfConnectedTokens == 4)
                {
                    winnerOutput(lastFoundToken);
                    return 0;
                }
                iterator++;
            }
            numberOfConnectedTokens = 0;
            std::cout << std::endl;
        }



        //ukos dolna część [/]<-
        lastFoundToken = '_';

        for (int column = xArrayDimentionLength - 3; column > 1; column--)
        {
            int iterator = 0;
            for (int row = yArrayDimentionLength; row >= column - 2; row--)
            {

                convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column + iterator);
                std::cout << "(" << row << ", " << convertedColumn << "), ";
                if (newGameArray[row][convertedColumn] != '_')
                {
                    if (newGameArray[row][convertedColumn] == lastFoundToken)
                    {
                        numberOfConnectedTokens++;
                    }
                    else
                    {
                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[row][convertedColumn];
                    }

                }
                else
                {
                    numberOfConnectedTokens = 0;
                }

                if (numberOfConnectedTokens == 4)
                {
                    winnerOutput(lastFoundToken);
                    return 0;
                }
                iterator++;
            }
            numberOfConnectedTokens = 0;
            std::cout << std::endl;
        }




        //ukos górna część ->[\]
        yArrayDimentionLength = 5;
        lastFoundToken = '_';
        for (int row = 2; row >= 0; row--)
        {
            int iterator = 0;
            for (int column = 1; column <= xArrayDimentionLength - row - 1; column++)
            {
                convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column);
                int iteratedRow = row + iterator;
                std::cout << "(" << iteratedRow << ", " << convertedColumn << "), ";
                if (newGameArray[iteratedRow][convertedColumn] != '_')
                {
                    if (newGameArray[iteratedRow][convertedColumn] == lastFoundToken)
                    {
                        numberOfConnectedTokens++;
                    }
                    else
                    {
                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[iteratedRow][convertedColumn];
                    }

                }
                else
                {
                    numberOfConnectedTokens = 0;
                }

                if (numberOfConnectedTokens == 4)
                {
                    winnerOutput(lastFoundToken);
                    return 0;
                }
                iterator++;
            }
            numberOfConnectedTokens = 0;
            std::cout << std::endl;
        }



        //ukos dolna część [\]<-
        yArrayDimentionLength = 5;
        xArrayDimentionLength = 7;
        lastFoundToken = '_';

        for (int column = 2; column <= xArrayDimentionLength - 3; column++)
        {
            int iterator = 0;
            for (int row = 0; row <= xArrayDimentionLength - column; row++)
            {

                convertedColumn = convertInputTokenPositionIntoPositionInGameArray(column + iterator);
                std::cout << "(" << row << ", " << convertedColumn << "), ";
                if (newGameArray[row][convertedColumn] != '_')
                {
                    if (newGameArray[row][convertedColumn] == lastFoundToken)
                    {
                        numberOfConnectedTokens++;
                    }
                    else
                    {
                        numberOfConnectedTokens = 1;
                        lastFoundToken = newGameArray[row][convertedColumn];
                    }

                }
                else
                {
                    numberOfConnectedTokens = 0;
                }

                if (numberOfConnectedTokens == 4)
                {
                    winnerOutput(lastFoundToken);
                    return 0;
                }
                iterator++;
            }
            numberOfConnectedTokens = 0;
            std::cout << std::endl;
        }


    }
        std::cout << "Draw" << std::endl;
        system("pause");
        return 0;
    

}