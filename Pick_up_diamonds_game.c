#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
void printBoard(int, int);
void printCharacter(int, int, int);
void printDiamond(int, int, int, int);

int main()
{
    int rows;
    int cols;
    int quit = 0;
    int posX;
    int posY;
    int posDiamondX;
    int posDiamondY;
    char key;

    printf("Set the number of columns: ");
    scanf("%d", &cols);
    printf("\nSet the number of rows: ");
    scanf("%d", &rows);
    posX = cols / 2;
    posY = rows / 2;

    printf("\e[?25l");
    while (!quit)
    {
        printf("\e[1;1H\e[2J"); // clears console
        printBoard(rows, cols);
        printCharacter(rows, posY, posX);
        // printDiamond(rows, cols, posY, posX);
        if (kbhit)
        {
            key = getch();
            if ((int)key == 27)
            { // esc
                quit = 1;
                break;
            }
            if ((int)key == 119 && posY > 1) // w
                posY--;
            if ((int)key == 115 && posY < rows) // s
                posY++;
            if ((int)key == 97 && posX > 1) // a
                posX--;
            if ((int)key == 100 && posX < cols) // d
                posX++;
        }
    };
    printf("\e[%iF", rows / 2);
    printf("test");
    printf("\e[?25h"); // makes cursor visible
    return 0;
}

void printBoard(int rows, int cols)
{
    printf("Press ESC to escape");
    printf("\n┌");
    for (int i = 0; i < cols; i++)
    {
        printf("─");
    }
    printf("┐\n");
    for (int i = 0; i < rows; i++)
    {
        printf("|");
        for (int j = 0; j < cols; j++)
        {
            printf("·");
        }
        printf("|\n");
    }

    printf("└");
    for (int i = 0; i < cols; i++)
    {
        printf("─");
    }
    printf("┘\n");
}

void printCharacter(int rows, int posY, int posX)
{
    printf("\e[%iA", rows + 2);
    printf("\e[%iB\e[%iC█", posY, posX);
}

void printDiamond(int rows, int cols, int posY, int posX)
{
    srand(time(0));
    int posDiamondY = rows;
    int posDiamondX = cols;

    printf("\e[%iA", rows + 2);
    while (posY == posDiamondY || posX == posDiamondX)
    {
        posDiamondY = (rand() % rows) + 1;
        posDiamondX = (rand() % cols) + 1;
    }
    printf("\e[%iB\e[%iC░", posDiamondY, posDiamondX);
}