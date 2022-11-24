#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void delay(int a )
{
    int add;
    int time;
    int i;
    time=a*50000000;
    for(i=0; i<time; i++)
    {
        add*=i;
        add++;
        add++;
    }
}
int i, j, height = 20, width = 20;
int gameover, point;
int x, y, fruitx, fruity, flag;

// Function to generate the fruit
// within the boundary
void setup()
{
    gameover = 0;
// Stores height and width
    x = height / 2;
    y = width / 2;
label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    point = 0;
}
// Function to draw the boundaries
void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1
                    || j == 0
                    || j == height - 1)
            {
                printf("X");
            }
            else
            {
                if (i == x && j == y)
                    printf("R");
                else if (i == fruitx
                         && j == fruity)
                    printf("@");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    // Print the point after the
    // game ends
    printf("Point = %d", point);
    printf("\n");
    printf("R=up\nD=left\t G=right\nV=down\n");
    printf("press E to Exit the game\nRakib 2020831051");
}
// Function to take the input
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'd':
            flag = 1;
            break;
        case 'v':
            flag = 2;
            break;
        case 'g':
            flag = 3;
            break;
        case 'r':
            flag = 4;
            break;
        case 'e':
            gameover = 1;
            break;
        }
    }
}
// Function for the logic behind
// each movement
void logic()
{
    sleep(0.01);
    switch (flag)
    {
    case 1:
        y--;
        delay(1);
        break;
    case 2:
        x++;
        delay(1);
        break;
    case 3:
        y++;
        delay(1);
        break;
    case 4:
        x--;
        delay(1);
        break;
    default:
        break;
    }
    // If the game is over
    if (x < 0 || x > height
            || y < 0 || y > width)
        gameover = 1;
    // If snake reaches the fruit
    // then update the point
    if (x == fruitx && y == fruity)
    {
label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;
        // After eating the above fruit
        // generate new fruit
label4:
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4;
        point += 10;
    }
}
// Driver Code
void main()
{
    int m, n;
    // Generate boundary
    setup();
    // Until the game is over
    while (!gameover)
    {
        // Function Call
        draw();
        input();
        logic();
    }
}
