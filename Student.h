#ifndef STUDENT_H
#define STUDENT_H


#define ATTEMPTS          3

#define ARRAY_LENGTH      10

#define NAME_LENGTH       60
#define PHONE_LENGTH      50
#define BIRTHDAT_LENGTH   20


typedef struct
{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char birthday[BIRTHDAT_LENGTH];
    char gender;
    float totalScore;
    float computerScore;
    float mathScore;
    float arabicScore;
    float englishScore;
    int id;
}STUDENT;


/*function prototype*/

/*function displays the welcome screen and targeted activates*/
void MAIN_MENU(void);

/*this function creates a new student account*/
void NEW_STUDENT(void);

/*this function is for deleting a student account*/
void DELETE_STUDENT(void);

/*this function displays all students information */
void STUDENT_LIST(void);

/*this function has been used for updating a particular student account*/
void STUDENT_EDIT(void);

/*this function can sort all students according to computer science score*/
void RANK_STUDENT(void);

/*– this function has been used for updating score of all students*/
void STUDENT_SCORE(void);

/*this function displays a particular student account*/
void DISPLAY_STUDENT(void);


/*this function can sort all students according to total score*/
void RANK_STUDENT_TOTAL(void);

/*this function can close program*/
void CLOSE_PROGRAMME(void);

/*this function displays number of students at this school*/
void NOM_STUDENTS(void);

/*this function can show invalid message*/
void Invalid(void);


#endif // STUDENT_H

