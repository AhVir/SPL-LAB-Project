#include <stdio.h>
#include <string.h>
#include <windows.h> //Header file for animation purposes

/*Animation Settings:*/
int SLEEPTIME = 25;
int EXIT = 25;

typedef struct
{
    char name[100];
    int age;
    char role[30];
    int match;
    int total_run;
    int highest_run;
} PLAYER;

/*Function prototype that contains menu list*/
void menuList();

/*Main Function*/
int main()
{
    printf("\n\n");

    /*Start & End Text*/
    char start[] = " Program is starting.\n Loading.........\n Loaded!\n\n";
    char bye[] = "Exiting the Program, Assalamualaikum!";

    int i = 0;
    /*Loading Screen Animation*/
    while (start[i] != '\0')
    {
        printf("%c", start[i++]);
        Sleep(10);
    }

    /*File name input & Taking info from the file*/
    printf("Input The File Name: ");
    char fileName[100];
    gets(fileName);

    FILE *fl = fopen(fileName, "r");

    int numberOfPlayers;
    fscanf(fl, "%d ", &numberOfPlayers);
    PLAYER players[numberOfPlayers];

    float value[numberOfPlayers], average[numberOfPlayers];

    /*Taking input from file*/
    for (int i = 0; i < numberOfPlayers; i++)
    {
        fgets(players[i].name, sizeof(players[i].name), fl);
        players[i].name[strcspn(players[i].name, "\n")] = '\0';
        fscanf(fl, "%d ", &players[i].age);
        fgets(players[i].role, sizeof(players[i].role), fl);
        players[i].role[strcspn(players[i].role, "\n")] = '\0';
        fscanf(fl, "%d %d %d ", &players[i].match, &players[i].total_run, &players[i].highest_run);
    }

    /*Calculating the averages*/
    for (int i = 0; i < 6; i++)
    {
        average[i] = (((float)players[i].total_run) / players[i].match);
    }

    /*Infinite Prompt*/
    while (1)
    {
        menuList();
        printf("  ->");
        int choice;
        scanf("%d", &choice);
        fflush(stdin);

        /*Choice 01: */
        if (choice == 1)
        {
            puts("  All Players' Name:- ");
            for (int i = 0; i < numberOfPlayers; i++)
            {
                printf("\t");
                puts(players[i].name);
            }
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);
            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 02: */
        if (choice == 2)
        {
            char name[100];
            printf("  Player's Name: ");
            gets(name);

            int plyr = -1;
            for (int i = 0; i < 6; i++)
            {
                if (strcmp(players[i].name, name) == 0)
                {
                    plyr = i;
                    break;
                }
            }
            if (plyr == -1)
            {
                printf("  Player not FOUND! Enter Valid Player Name.\n");

                /*Return Menu*/
                printf("  1. Exit\n  2. Go to Main Menu\n");
                printf("  ->");
                int n;
                scanf("%d", &n);

                if (n == 1)
                {
                    int i = 0;
                    while (bye[i] != '\0')
                    {
                        printf("%c", bye[i++]);
                        Sleep(EXIT);
                    }
                    return 0;
                }
            }
            else
            {
                puts("  Inputted Player's Info:- ");
                printf("\tName: ");
                puts(players[plyr].name);
                printf("\tAge: %d\n", players[plyr].age);
                printf("\tRole: ");
                puts(players[plyr].role);
                printf("\tMatch Played: %d\n\tTotal Run: %d\n\tHighest Run: %d\n", players[plyr].match, players[plyr].total_run, players[plyr].highest_run);

                /*Return Menu*/
                printf("  1. Exit\n  2. Go to Main Menu\n");
                printf("  ->");
                int n;
                scanf("%d", &n);

                if (n == 1)
                {
                    int i = 0;
                    while (bye[i] != '\0')
                    {
                        printf("%c", bye[i++]);
                        Sleep(EXIT);
                    }
                    return 0;
                }
            }
        }

        /*Choice 03: */
        if (choice == 3)
        {
            int mostExpPlayer = 0;
            for (int i = 1; i < 6; i++)
            {
                if (players[i].match > players[mostExpPlayer].match)
                    mostExpPlayer = i;
            }
            printf("\tMEP:- ");
            puts(players[mostExpPlayer].name);
            printf("\tMatch Played: %d\n", players[mostExpPlayer].match);
            printf("\tRole: ");
            puts(players[mostExpPlayer].role);
            printf("\tTotal Run: %d\n\tHighest Run: %d\n", players[mostExpPlayer].total_run, players[mostExpPlayer].highest_run);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 04: */
        if (choice == 4)
        {
            int newCommer = 0;
            for (int i = 1; i < 6; i++)
            {
                if (players[newCommer].age > players[i].age)
                    newCommer = i;
            }
            printf("\tNCP: ");
            puts(players[newCommer].name);
            printf("\tAge: %d\n", players[newCommer].age);
            printf("\tMatch Played: %d\n", players[newCommer].match);
            printf("\tRole: ");
            puts(players[newCommer].role);
            printf("\tTotal Run: %d\n\tHighest Run: %d\n", players[newCommer].total_run, players[newCommer].highest_run);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 05: */
        if (choice == 5)
        {
            int topScorer = 0;
            for (int i = 1; i < 6; i++)
            {
                if (players[i].total_run > players[topScorer].total_run)
                    topScorer = i;
            }
            printf("\tNCP:- ");
            puts(players[topScorer].name);
            printf("\tAge: %d\n", players[topScorer].age);
            printf("\tTotal Run: %d\n", players[topScorer].total_run);
            printf("\tMatch Played: %d\n", players[topScorer].match);
            printf("\tHighest Run: %d\n", players[topScorer].total_run, players[topScorer].highest_run);
            printf("\tRole: ");
            puts(players[topScorer].role);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 06: */
        if (choice == 6)
        {
            int hardHitter = 0;
            for (int i = 1; i < 6; i++)
            {
                if (average[i] > average[hardHitter])
                    hardHitter = i;
            }
            printf("\tHHP:- ");
            printf("\t%s\n", players[hardHitter].name);
            printf("\tAverage: %.2f\n\tTotal Run: %d\n\tMatch Played: %d\n", average[hardHitter], players[hardHitter].total_run, players[hardHitter].match);
            printf("\tRole: %s\n", players[hardHitter].role);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 07: */
        if (choice == 7)
        {
            int highestRunTaker = 0;
            for (int i = 1; i < 6; i++)
            {
                if (players[i].highest_run > players[highestRunTaker].highest_run)
                    highestRunTaker = i;
            }
            printf("\tNCP:- ");
            printf("%s\n", players[highestRunTaker].name);
            printf("\tHighest Run: %d\n", players[highestRunTaker].highest_run);
            printf("\tAge: %d\n", players[highestRunTaker].age);
            printf("\tMatch Played: %d\n", players[highestRunTaker].match);
            printf("\tTotal Run: %d\n", players[highestRunTaker].total_run);
            printf("\tRole: ");
            puts(players[highestRunTaker].role);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*choice 08: */
        if (choice == 8)
        {
            for (int i = 0; i < 6; i++)
            {
                // printf("age-> %d, match-> %d, total-> %d, hRun-> %d, avg-> %f, %f, %d\n", players[i].age, players[i].match, players[i].total_run, players[i].highest_run, average[i], ((players[i].highest_run*1.0)/players[i].age), ((strcmp(players[i].role, "Allrounder")==0)?50:0));
                value[i] = players[i].age + players[i].match + players[i].total_run + players[i].highest_run + average[i] + ((players[i].highest_run * 1.0) / players[i].age) + ((strcmp(players[i].role, "Allrounder") == 0) ? 50 : 0);
                // printf("%f ", value[i]);
            }
            int mostValueablePlayer = 0;
            for (int i = 1; i < 6; i++)
            {
                if (value[i] > value[mostValueablePlayer])
                    mostValueablePlayer = i;
            }
            printf("\tMVP:- ");
            printf("%s\n", players[mostValueablePlayer].name);
            printf("\tValue: %.2f\n", value[mostValueablePlayer]);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 09: */
        if (choice == 9)
        {
            puts("\tAllrounders:- ");
            for (int i = 0; i < 6; i++)
                if (strcmp(players[i].role, "Allrounder") == 0)
                    printf("\t\t%s\n", players[i].name);

            /*Return Menu*/
            printf("  1. Exit\n  2. Go to Main Menu\n");
            printf("  ->");
            int n;
            scanf("%d", &n);

            if (n == 1)
            {
                int i = 0;
                while (bye[i] != '\0')
                {
                    printf("%c", bye[i++]);
                    Sleep(EXIT);
                }
                return 0;
            }
        }

        /*Choice 10: */
        /*Exit Option*/
        if (choice == 10)
        {
            int i = 0;
            while (bye[i] != '\0')
            {
                printf("%c", bye[i++]);
                Sleep(EXIT);
            }
            return 0;
        }

        /*Choice 11: */
        /*Extra Option For changing Animation Speed */
        if (choice == 11)
        {
        REPEAT:
            printf("\t\t1. Change Main Menu Animation Speed\n\t\t2. Change Exiting Animation Speed\n");
            printf("\t->");
            int input;
            scanf("%d", &input);
            if (input == 1)
            {
                printf("\t\t\tCurrent Speed: %d\n\t\t\tGive input in MiliSec(1s = 1000MiliSec): ", SLEEPTIME);
                printf("\n\t\t\t->");
                int in;
                scanf("%d", &in);
                SLEEPTIME = in;

                printf("\n\t\t\t**Setting has been updated Successfully!\n\n");

                /*Return Menu*/
                printf("\t\t\t1. Exit\n\t\t\t2. Go to Main Menu\n");
                printf("\t\t\t->");
                int n;
                scanf("%d", &n);

                if (n == 1)
                {
                    int i = 0;
                    while (bye[i] != '\0')
                    {
                        printf("%c", bye[i++]);
                        Sleep(EXIT);
                    }
                    return 0;
                }
            }
            else if (input == 2)
            {
                printf("\t\t\tCurrent Speed: %d\n\t\t\tGive input in MiliSec(1s = 1000MiliSec): ", EXIT);
                printf("\n\t\t\t->");
                int in;
                scanf("%d", &in);
                EXIT = in;

                printf("\n\t\t\t**Setting has been updated Successfully!\n\n");

                /*Return Menu*/
                printf("\t\t\t1. Exit\n\t\t\t2. Go to Main Menu\n");
                printf("\t\t\t->");
                int n;
                scanf("%d", &n);

                if (n == 1)
                {
                    int i = 0;
                    while (bye[i] != '\0')
                    {
                        printf("%c", bye[i++]);
                        Sleep(EXIT);
                    }
                    return 0;
                }
            }
            else
            {
                printf("\t\t\t**Invalid Choice!**\n\n");

                /*Return Menu*/
                printf("\t\t\t1. Try Again\n\t\t\t2. Exit\n\t\t\t3. Go to Main Menu\n");
                printf("\t\t\t->");
                int n;
                scanf("%d", &n);

                if (n == 1)
                    goto REPEAT;  //Going back to line 423

                else if (n == 2)
                {
                    int i = 0;
                    while (bye[i] != '\0')
                    {
                        printf("%c", bye[i++]);
                        Sleep(EXIT);
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}

/*Function that contains menu list*/
void menuList()
{
    puts("  :~$Main Menu: ");
    Sleep(SLEEPTIME);
    puts("\t\t\t1. Show ALL PLayers");
    Sleep(SLEEPTIME);
    puts("\t\t\t2. Show A Particular player information (Provide Player Name)");
    Sleep(SLEEPTIME);
    puts("\t\t\t3. Show the MOST Experienced Player(MEP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t4. Show the New Comer Player (NCP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t5. Show the Top Scorer Player (TSP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t6. Show the Hard Hitter Player (HHP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t7. Show the Highest Run Taker Player (HRTP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t8. Show the MOST Valuable Player (MVP)");
    Sleep(SLEEPTIME);
    puts("\t\t\t9. Show the Allrounders");
    Sleep(SLEEPTIME);
    puts("\t\t\t10. Exit/Quit");
    Sleep(SLEEPTIME);
    puts("\t\t\t11. Settings");
    Sleep(SLEEPTIME);
}