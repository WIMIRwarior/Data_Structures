#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_item{

int value;
struct List_item* NEXT;
struct List_item* PREV;

}List_item;


void Push_Head(int val, List_item** head, List_item** tail,int* number_of_elements)
{

    List_item* new_element = (List_item*)malloc(sizeof(List_item));
    List_item* old_head = *head;

     if(*number_of_elements==0)
    {
        *head = new_element;
        *tail = new_element;
        new_element->value=val;
        new_element->NEXT=NULL;
        new_element->PREV=NULL;
    }
    else{
    old_head->NEXT=new_element;
    new_element->value=val;
    new_element->NEXT=NULL;
    new_element->PREV=old_head;
    }
    *head=new_element;
    (*number_of_elements)++;

    printf(" %d was added to the head of the list.\nNumber of items: %d\n",val,*number_of_elements);
}

int Pop_HEAD(List_item** head, int* number_of_elements)
{
   if(*number_of_elements==0)
    {
        printf("\n***ERROR: EMPTY LIST***\n");
        return 1;
    }
    int val;
    List_item* old_head;

    old_head = *head;
    val=(*head)->value;
    *head = (*head)->PREV;

    free(old_head);
    (*number_of_elements)--;

    printf(" %d was taken from the head of the list.\nNumber of items: %d\n",val,*number_of_elements);

    return val;
}

void Push_TAIL(int val, List_item** head,List_item** tail,int* number_of_elements)
{

    List_item* new_element = (List_item*)malloc(sizeof(List_item));
    List_item* old_tail = *tail;

    if(*number_of_elements==0)
    {
        *head = new_element;
        *tail = new_element;
        new_element->value=val;
        new_element->PREV=NULL;
        new_element->NEXT=NULL;
    }
    else
    {
    old_tail->PREV=new_element;
    new_element->value=val;
    new_element->PREV=NULL;
    new_element->NEXT=old_tail;
    }
    *tail=new_element;
    (*number_of_elements)++;

    printf(" %d was added to the tail of the list.\nNumber of items: %d\n",val,*number_of_elements);
}

int Pop_TAIL(List_item** tail,int* number_of_elements)
{
    if(*number_of_elements==0)
    {
        printf("\n***ERROR: EMPTY LIST***\n");
        return 1;
    }
    int val;
    List_item* old_tail;

    old_tail = *tail;
    val=(*tail)->value;
    *tail = (*tail)->NEXT;

    free(old_tail);
    (*number_of_elements)--;

    printf(" %d was taken from the tail of the list.\nNumber of items: %d\n",val,*number_of_elements);

    return val;
}


int main()
{
    int number_of_elements=0,val;
	struct List_item* HEAD=NULL;
	struct List_item* TAIL=NULL;
    char input[20];

    while(scanf("%19s",input)>0)
    {
        if(strcmp(input,"Push_HEAD")==0)
        {
            scanf("%d",&val);
            Push_Head(val,&HEAD,&TAIL,&number_of_elements);
            continue;
        }
        if(strcmp(input,"Pop_HEAD")==0)
        {
            Pop_HEAD(&HEAD,&number_of_elements);
            continue;
        }
        if(strcmp(input,"Push_TAIL")==0)
        {
            scanf("%d",&val);
            Push_TAIL(val,&HEAD,&TAIL,&number_of_elements);
            continue;
        }
        if(strcmp(input,"Pop_TAIL")==0)
        {
            Pop_TAIL(&TAIL,&number_of_elements);
            continue;
        }
        if(strcmp(input,"EXIT")==0)
            break;
        printf("\n***ERROR: INVALID COMMAND***\n");
    }



return 0;}
