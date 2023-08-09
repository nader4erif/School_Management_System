#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "LinkedList.h"


static int user_attempts = 0;
static const char password[5]= "1234";

int main()
{
    char pass[5];
    printf("************************************************\n");
    printf("*********** School Management System ***********\n");
    printf("******************** log in ********************\n");
    printf("************************************************\n");
    delay(3);
    system("cls");
    while(1)
    {
        printf("please enter admin password: ");
        scanf(" %[^\n]", pass);
        if(StringCompare(password, pass))
        {
            system("cls");
            MAIN_MENU();
        }
        else
        {
            printf("wrong Password! please try again..\n");
            user_attempts++;
            countingDelay(3);
            system("cls");
        }
        if(user_attempts >= ATTEMPTS)
        {
            printf("Try again after 10 sec..\n");
            user_attempts = 0;
            countingDelay(10);
            system("cls");
        }
    }

    return 0;
}
