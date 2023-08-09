#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "LinkedList.h"
#include "Utils.h"

node_t* head = NULLPTR;
static int NoStudent = 0;

                                                   /*lookup table*/
static const void(*menu_pf[ARRAY_LENGTH])(void) = {CLOSE_PROGRAMME,         /*pointer of a function to close program*/
                                                   NEW_STUDENT,             /*pointer of a function to add new student*/
                                                   DELETE_STUDENT,          /*pointer of a function to delete student*/
                                                   DISPLAY_STUDENT,         /*pointer of a function to display student*/
                                                   STUDENT_LIST,            /*pointer of a function to print all student info*/
                                                   STUDENT_EDIT,            /*pointer of a function to edit student info*/
                                                   RANK_STUDENT,            /*pointer of a function to rank student according to CS score*/
                                                   RANK_STUDENT_TOTAL,      /*pointer of a function to rank student according to total score*/
                                                   STUDENT_SCORE,           /*pointer of a function to  updating score of all students*/
                                                   NOM_STUDENTS             /*pointer of a function to  print no. students*/
                                                  };


/*function displays the welcome screen and targeted activates*/
void MAIN_MENU(void)
{
    unsigned int choice;

    printf("*********** Welcome To NTI School ***********\n");
    delay(3);
    system("cls");
    while (1)
    {
        printf("************************************************\n");
        printf("********* School Management System Menu ********\n");
        printf("************************************************\n");
        printf("1. New Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Student\n");
        printf("4. Student List\n");
        printf("5. Edit Student Details\n");
        printf("6. Rank Students by Computer Science Score\n");
        printf("7. Rank Students by Computer Total Score\n");
        printf("8. Update Student Scores\n");
        printf("9. Number of Students in School\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice <= 9)
        {
            menu_pf[choice]();
        }
        else
        {
            Invalid();
        }
    }
}


/*this function creates a new student account*/
void NEW_STUDENT(void)
{
    system("cls");
    STUDENT NewStudent;
    printf("Enter Student information:\n");
    printf("Student Name: ");
    scanf(" %[^\n]", NewStudent.name);
    printf("Student ID: ");
    scanf("%d", &(NewStudent.id));
    printf("Student Birthday (DD/MM/Year): ");
    scanf(" %[^\n]", NewStudent.birthday);
    printf("Student Phone number: ");
    scanf(" %[^\n]", NewStudent.phone);
    printf("Student Gender (M/F): ");
    scanf(" %c", &(NewStudent.gender));
    printf("Computer Score from 0 to 25: ");
    scanf("%f", &(NewStudent.computerScore));
    printf("Math Score from 0 to 25: ");
    scanf("%f", &(NewStudent.mathScore));
    printf("Arabic Score from 0 to 25: ");
    scanf("%f", &(NewStudent.arabicScore));
    printf("English Score from 0 to 25: ");
    scanf("%f", &(NewStudent.englishScore));
    NewStudent.totalScore = (NewStudent.computerScore+NewStudent.mathScore+NewStudent.arabicScore+NewStudent.englishScore);
    printf("percentage : %.1f%%\n", NewStudent.totalScore);

    /* Add the new student to the linked list */
    List_AddNodeToLast(&head, NewStudent);
    printf("New student added successfully!\n");
    NoStudent++;
    countingDelay(3);
    system("cls");

}


/*this function is for deleting a student account*/
void DELETE_STUDENT(void)
{
    system("cls");
    int id;
    printf("Enter the Student ID to delete: ");
    scanf("%d", &id);

    /* Remove the student from the linked list using ID */
    list_status status = List_RemoveNode(&head, id);
    if(status == LIST_OK)
    {
        printf("student removeded successfully!\n");
        NoStudent--;
    }
    else
    {
        printf("Not Found student with id [%d]!\n", id);
    }

    countingDelay(3);
    system("cls");

}


/*this function displays the students information */
void STUDENT_LIST(void)
{
    system("cls");
    node_t* current = head;
    (void)List_Sort(current, ALPHABETICAL_ORDER);
    printf("=============================================================================================================================================================================\n");
    printf("| %-5s | %-40s | %-6s | %-15s | %-12s | %-11s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "No.", "Name", "ID", "Gender", "Phone", "Birthday", "Percentage", "Computer", "Math", "Arabic", "English");
    printf("=============================================================================================================================================================================\n");
    /*print all student in alphabetical order*/
    List_Print(current);
    back_MainMenu();
}


/*this function has been used for updating a particular student account*/
void STUDENT_EDIT(void)
{
    system("cls");
    int id;
    printf("Enter the Student ID to Edit: ");
    scanf("%d", &id);

    /*edit student*/
    STUDENT EditedStudent;
    printf("Enter Student information:\n");
    printf("Student Name: ");
    scanf(" %[^\n]", EditedStudent.name);
    printf("Student ID: ");
    scanf("%d", &(EditedStudent.id));
    printf("Student Birthday (DD/MM/Year): ");
    scanf(" %[^\n]", EditedStudent.birthday);
    printf("Student Phone number: ");
    scanf(" %[^\n]", EditedStudent.phone);
    printf("Student Gender (M/F): ");
    scanf(" %c", &(EditedStudent.gender));
    printf("Computer Score from 0 to 25: ");
    scanf("%f", &(EditedStudent.computerScore));
    printf("Math Score from 0 to 25: ");
    scanf("%f", &(EditedStudent.mathScore));
    printf("Arabic Score from 0 to 25: ");
    scanf("%f", &(EditedStudent.arabicScore));
    printf("English Score from 0 to 25: ");
    scanf("%f", &(EditedStudent.englishScore));
    EditedStudent.totalScore = (EditedStudent.computerScore+EditedStudent.mathScore+EditedStudent.arabicScore+EditedStudent.englishScore);
    printf("percentage : %.1f%%\n", EditedStudent.totalScore);

    /* Add the new student to the linked list */
    (void)List_EditData(head, EditedStudent, id);
    printf("student Edited successfully!\n");
    countingDelay(3);
    system("cls");

}


/*this function can sort all students according to computer science score*/
void RANK_STUDENT(void)
{
    system("cls");
    node_t *current = head;
    /*sorting students according to computer science score*/
    List_Sort(current, CS_SCORE);
    printf("=============================================================================================================================================================================\n");
    printf("| %-5s | %-40s | %-6s | %-15s | %-12s | %-11s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "No.", "Name", "ID", "Gender", "Phone", "Birthday", "Percentage", "Computer", "Math", "Arabic", "English");
    printf("=============================================================================================================================================================================\n");
    /*print all student in according to Cs score*/
    List_Print(current);
    back_MainMenu();
}


/*– this function has been used for updating score of all students*/
void STUDENT_SCORE(void)
{
    int id = 0;
    system("cls");
    printf("Enter the Student ID to Edit Score (-1 to exit): ");
    scanf("%d", &id);
    while(id != -1)
    {
        STUDENT EditedStudent;
        printf("Computer Score from 0 to 25: ");
        scanf("%f", &(EditedStudent.computerScore));
        printf("Math Score from 0 to 25: ");
        scanf("%f", &(EditedStudent.mathScore));
        printf("Arabic Score from 0 to 25: ");
        scanf("%f", &(EditedStudent.arabicScore));
        printf("English Score from 0 to 25: ");
        scanf("%f", &(EditedStudent.englishScore));
        EditedStudent.totalScore = (EditedStudent.computerScore+EditedStudent.mathScore+EditedStudent.arabicScore+EditedStudent.englishScore);
        printf("percentage : %.1f%%\n", EditedStudent.totalScore);

        /* Add the edited student to the linked list */
        (void)List_EditScore(head, EditedStudent, id);
        printf("student Score Edited successfully!\n");
        countingDelay(3);
        system("cls");
        printf("Enter the Student ID to Edit Score (-1 to exit): ");
        scanf("%d", &id);
    }
    countingDelay(3);
    system("cls");
}



/*this function displays a particular student account*/
void DISPLAY_STUDENT(void)
{
    system("cls");
    node_t* current = head;
    int id;
    printf("Enter the Student ID to Display: ");
    scanf("%d", &id);
    printf("Student [%d] informations:\n", id);
    printf("=====================================================================================================================================================================\n");
    printf("| %-40s | %-6s | %-15s | %-12s | %-11s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "Name", "ID", "Gender", "Phone", "Birthday", "Percentage", "Computer", "Math", "Arabic", "English");
    printf("=====================================================================================================================================================================\n");
    Node_Print(current, id);
    back_MainMenu();
}



/*this function can sort all students according to total score*/
void RANK_STUDENT_TOTAL(void)
{
    system("cls");
    node_t *current = head;
    List_Sort(current, TOTAL_SCORE);
    printf("=============================================================================================================================================================================\n");
    printf("| %-5s | %-40s | %-6s | %-15s | %-12s | %-11s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "No.", "Name", "ID", "Gender", "Phone", "Birthday", "Percentage", "Computer", "Math", "Arabic", "English");
    printf("=============================================================================================================================================================================\n");
    List_Print(current);
    back_MainMenu();
}

/*this function can close program*/
void CLOSE_PROGRAMME(void)
{
    system("cls");
    printf("Exiting... Goodbye!\n");
    countingDelay(3);
    exit(0);
}


/*this function displays number of students at this school*/
void NOM_STUDENTS(void)
{
    system("cls");
    printf("There is %d students at school..\n", NoStudent);
    back_MainMenu();
}


/*this function can show invalid message*/
void Invalid(void)
{
    system("cls");
    printf("Invalid choice.. Try again.\n");
    countingDelay(3);
    system("cls");
}





