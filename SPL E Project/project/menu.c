#include <stdio.h>
#include "menu.h"

typedef struct
{
    char name[100];
    int age;
    char role[30];
    int match;
    int total_run;
    int highest_run;
} PLAYER;

void allPlayers(PLAYER p, FILE *file)
{
    printf("Name: ");
    puts(p.name);
    puts("\nAge: ");
    printf("%d\nRole: ", p.age);
    puts(p.role);
    printf("\nMatch Played: %d\nTotal Run: %d\nHighest Run: %d\n", p.match, p.total_run, p.highest_run);
    puts("\n");
}

int main()
{
    printf("Input The File Name: ");
    char fileName[100];
    gets(fileName);
    FILE *fl = fopen(fileName, "r");

    int numberOfPlayers;
    fscanf(fl, "%d ", &numberOfPlayers);
    PLAYER players[numberOfPlayers];

    while (1)
    {
        menuList();
        int choice;
        scanf("%d ", &choice);

        if (choice == 10)
            break;

        if (choice == 1)
        {
            printf("Type the file name you want to get the output: ");
            char outputFileName[100];
            gets(outputFileName);
            FILE *fl2 = fopen(outputFileName, "w");

            for (int i = 0; i < numberOfPlayers; i++)
            {
                fprintf(fl2, "Name: ");
                fputs(players[i].name, fl2);
                fputs("\nAge: ", fl2);
                fprintf(fl2, "%d\nRole: ", players[i].age);
                fputs(players[i].role, fl2);
                fprintf(fl2, "\nMatch Played: %d\nTotal Run: %d\nHighest Run: %d\n", players[i].match, players[i].total_run, players[i].highest_run);
                fputs("\n", fl2);
                // allPlayers(players[i], fl2);
            }
        }
    }

    return 0;
}