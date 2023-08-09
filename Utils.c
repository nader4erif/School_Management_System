#include <stdio.h>
#include "utils.h"


/*Function to introduce a delay in seconds*/
void delay(int seconds) {
    time_t start_time, current_time;
    time(&start_time);
    do {
        time(&current_time);
    } while ((current_time - start_time) < seconds);
}

/*Function to count using delay in seconds*/
void countingDelay(int num)
{
    for(int i = 1; i<= num; i++)
    {
        printf("%d.. ", i);
        delay(1);
    }
}

/*function to back to main menu*/
void back_MainMenu(void)
{
    char clr;
    printf("Press (c) to back to main menu: ");
    scanf(" %c", &clr);
    if(clr == 'c')
    {
        countingDelay(3);
        system("cls");
    }
}


/*function to compare between two strings*/
int StringCompare(char *s1,char*s2)
{
    int i;

    for(i=0; s1[i]||s2[i]; i++)
    {
        if(s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}
