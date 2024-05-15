#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct el
{
    int value;
    struct el_stosu* next;
}el_stosu;

void Push(int val,el_stosu** ptr)
{
    el_stosu* nowy_element = (el_stosu*)malloc(sizeof(nowy_element));
    nowy_element->value = val;
    nowy_element->next = *ptr;
    *ptr=nowy_element;
    printf("Wrzucilem %d na stos\n",val);
}


int Pop(el_stosu** ptr)
{
    if((*ptr)==NULL)
    {
      printf("\n****ERROR***\n****EMPTY STACK***\n\n");
      return 1;
    }

    int val;
    el_stosu* old_ptr;
    old_ptr = *ptr;
    val=(*ptr)->value;
    *ptr = (*ptr)->next;
    free(old_ptr);

printf("Zdjalem %d ze stosu\n",val);
return val;
}









int main()
{
    int val;
    char input[30];
    el_stosu* nowy_stos= NULL;
    while(scanf("%s",input)>0)
    {
        printf("Wczytalem %s\n",input);

        if(strcmp(input,"Push")==0)
        {
            scanf("%d",&val);
            Push(val,&nowy_stos);
            continue;
        }

        if(strcmp(input,"Pop")==0)
        {
            Pop(&nowy_stos);
            continue;
        }
            printf("\n***ERROR***\n***INVALID COMMAND***\n\n");
    }
    return 0;
}
