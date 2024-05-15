#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el_listy{

int value;
struct el_listy* NEXT;
struct el_listy* PREV;

}el_listy;


void Push_Head(int val, el_listy** head, el_listy** tail,int* number_of_elements)
{

    el_listy* new_element = (el_listy*)malloc(sizeof(el_listy));
    el_listy* old_head = *head;

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

    printf("Wrzucono %d na czolo listy.\nLiczba elementow listy: %d\n",val,*number_of_elements);
}

int Pop_HEAD(el_listy** head, int* number_of_elements)
{
   if(*number_of_elements==0)
    {
        printf("\n***ERROR: EMPTY LIST***\n");
        return 1;
    }
    int val;
    el_listy* old_head;

    old_head = *head;
    val=(*head)->value;
    *head = (*head)->PREV;

    free(old_head);
    (*number_of_elements)--;

    printf("Zdjalem z czola listy %d.\nLiczba elementow listy: %d\n",val,*number_of_elements);

    return val;
}

void Push_TAIL(int val, el_listy** head,el_listy** tail,int* number_of_elements)
{

    el_listy* new_element = (el_listy*)malloc(sizeof(el_listy));
    el_listy* old_tail = *tail;

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

    printf("Wrzucono %d na ogon listy.\nLiczba elementow listy: %d\n",val,*number_of_elements);
}

int Pop_TAIL(el_listy** tail,int* number_of_elements)
{
    if(*number_of_elements==0)
    {
        printf("\n***ERROR: EMPTY LIST***\n");
        return 1;
    }
    int val;
    el_listy* old_tail;

    old_tail = *tail;
    val=(*tail)->value;
    *tail = (*tail)->NEXT;

    free(old_tail);
    (*number_of_elements)--;

    printf("Zdjalem z ogona listy %d.\nLiczba elementow listy: %d\n",val,*number_of_elements);

    return val;
}


int main()
{
    int number_of_elements=0,val;
	struct el_listy* HEAD=NULL;
	struct el_listy* TAIL=NULL;
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
        printf("\n***ERROR: WRONG COMMAND***\n");
    }



return 0;}
