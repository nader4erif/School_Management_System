#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



/*function to create node*/
node_t* Create_Node(STUDENT data)
{
    node_t* NewNode = (node_t*)malloc(sizeof(node_t));
    NewNode->dataStudent = data;
    NewNode->next = NULLPTR;
    return NewNode;
}

/*function to add node at last*/
void List_AddNodeToLast(node_t** phead, STUDENT data)
{
    node_t* NewNode = Create_Node(data);
    node_t* current = *phead;
    if(*phead == NULLPTR)
    {
        *phead = NewNode;
        return;
    }
    while(current->next != NULLPTR)
    {
        current = current->next;
    }
    current->next = NewNode;
}

/*function to edit data*/
list_status List_EditData(node_t* head, STUDENT NewData, int id)
{
    if(head == NULLPTR)
    {
        return EMPTY_LIST;
    }
    node_t* current = head;
    while(current != NULLPTR)
    {
        if(current->dataStudent.id == id)
        {
            current->dataStudent = NewData;
            return LIST_OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}

/*function to add node at first*/
void List_AddNodeToFirst(node_t** phead, STUDENT data)
{
    node_t* NewNode = Create_Node(data);
    NewNode->next = *phead;
    *phead = NewNode;
}

/*function to delete data from list*/
list_status List_RemoveNode(node_t** phead, int id)
{
    node_t* current = *phead;
    node_t* temp;
    if(*phead == NULLPTR)
    {
        return EMPTY_LIST;
    }
    else if((*phead)->dataStudent.id == id )
    {
        temp = *phead;
        *phead = (*phead)->next;
        free(temp);
    }
    else
    {
        while(current->next != NULLPTR)
        {
            if(current->next->dataStudent.id == id)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                return LIST_OK;
            }
            current = current->next;
        }
        return NOT_FOUND;
    }
}

/*function to insert node after particular node*/
list_status List_InsertAfter(node_t** phead, int id, STUDENT NewData)
{
    node_t* NewNode = Create_Node(NewData);
    node_t* current = *phead;
    node_t* temp;
    while(current != NULLPTR)
    {
        if(current->dataStudent.id == id)
        {
            temp = current->next;
            current->next = NewNode;
            NewNode->next = temp;
            return LIST_OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}

/*function to print list*/
void List_Print(node_t* head)
{
    node_t* current = head;
    int count = 1;
    while(current != NULLPTR)
    {
        printf("| %-5d | %-40s | %-6d | %-15c | %-12s | %-11s | %-10.1f | %-10.2f | %-10.2f | %-10.2f | %-10.2f |\n",
               count, current->dataStudent.name, current->dataStudent.id, current->dataStudent.gender,
               current->dataStudent.phone, current->dataStudent.birthday, current->dataStudent.totalScore,
               current->dataStudent.computerScore, current->dataStudent.mathScore, current->dataStudent.arabicScore,
               current->dataStudent.englishScore);
        current = current->next;
        count++;
    }

    if(count == 1)
    {
        printf("Empty List, no student founded!\n");
    }
    printf("=============================================================================================================================================================================\n");

}

/*function to print one node*/
void Node_Print(node_t* head, int id)
{
    node_t* current = head;
    while(current != NULLPTR)
    {
        /* Print the information of the student with the specified ID */

        if(current->dataStudent.id == id)
        {
            printf("| %-40s | %-6d | %-15c | %-12s | %-11s | %-10.1f | %-10.2f | %-10.2f | %-10.2f | %-10.2f |\n",
                   current->dataStudent.name, current->dataStudent.id, current->dataStudent.gender,
                   current->dataStudent.phone, current->dataStudent.birthday, current->dataStudent.totalScore,
                   current->dataStudent.computerScore, current->dataStudent.mathScore, current->dataStudent.arabicScore,
                   current->dataStudent.englishScore);
            printf("=====================================================================================================================================================================\n");

            /* Exit the function after printing the student information */
            return;
        }
        current = current->next;
    }

    /* If the function reaches here, it means the student with the specified ID was not found */
    printf("Student with ID[%d] Not Found!\n", id);
}



/*function to print sorted list of students based on different criteria*/
void List_Sort(node_t* head, sort_t sorting)
{
    node_t *current = head;
    node_t *after = NULLPTR;
    STUDENT temp;
    if(current == NULLPTR)
    {
        return;
    }
    if(current->next == NULLPTR)
    {
        printf("No need to sort a list with only one student!\n");
        return;
    }
    if(sorting == CS_SCORE)
    {
        while(current != NULLPTR)
        {
            after = current->next;
            while(after != NULLPTR)
            {
                if(current->dataStudent.computerScore < after->dataStudent.computerScore)
                {
                    temp = current->dataStudent;
                    current->dataStudent = after->dataStudent;
                    after->dataStudent = temp;
                }
                after = after->next;
            }
            current = current->next;
        }
    }
    if(sorting == TOTAL_SCORE)
    {
        while(current != NULLPTR)
        {
            after = current->next;
            while(after != NULLPTR)
            {
                if(current->dataStudent.totalScore < after->dataStudent.totalScore)
                {
                    temp = current->dataStudent;
                    current->dataStudent = after->dataStudent;
                    after->dataStudent = temp;
                }
                after = after->next;
            }
            current = current->next;
        }
    }
    if(sorting == ALPHABETICAL_ORDER)
    {
        while(current != NULLPTR)
        {
            after = current->next;
            while(after != NULLPTR)
            {
                if(current->dataStudent.name[0] > after->dataStudent.name[0])
                {
                    temp = current->dataStudent;
                    current->dataStudent = after->dataStudent;
                    after->dataStudent = temp;
                }
                after = after->next;
            }
            current = current->next;
        }
    }

}

/*function to edit only score*/
list_status List_EditScore(node_t* head, STUDENT NewData, int id)
{
    if(head == NULLPTR)
    {
        return EMPTY_LIST;
    }
    node_t* current = head;
    while(current != NULLPTR)
    {
        if(current->dataStudent.id == id)
        {
            current->dataStudent.computerScore = NewData.computerScore;
            current->dataStudent.mathScore = NewData.mathScore;
            current->dataStudent.arabicScore = NewData.arabicScore;
            current->dataStudent.englishScore = NewData.englishScore;
            current->dataStudent.totalScore = NewData.totalScore;
            return LIST_OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}
