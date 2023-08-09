#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"

#define NULLPTR ((void*)0)

typedef struct node
{
    STUDENT dataStudent;
    struct node* next;
}node_t;

typedef enum
{
    LIST_OK,
    EMPTY_LIST,
    NOT_FOUND
}list_status;


typedef enum
{
    CS_SCORE,
    TOTAL_SCORE,
    ALPHABETICAL_ORDER
}sort_t;

// single linked list //

/*function to create node*/
node_t* Create_Node(STUDENT data);

/*function to add node at last*/
void List_AddNodeToLast(node_t** phead, STUDENT data);

/*function to edit data*/
list_status List_EditData(node_t* head, STUDENT NewData, int id);

/*function to add node at first*/
void List_AddNodeToFirst(node_t** phead, STUDENT data);

/*function to delete data from list*/
list_status List_RemoveNode(node_t** phead, int id);

/*function to insert node after particular node*/
list_status List_InsertAfter(node_t** phead, int id, STUDENT NewData);

/*function to print list*/
void List_Print(node_t* head);

/*function to print one node*/
void Node_Print(node_t* head, int id);

/*function to print sorted list of students based on different criteria*/
void List_Sort(node_t* head, sort_t sorting);

/*function to edit only score*/
list_status List_EditScore(node_t* head, STUDENT NewData, int id);


#endif // LINKEDLIST_H
