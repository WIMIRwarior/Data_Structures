#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct stack_item
{
    int value;
    struct stack_item* next;
}stack_item;

void Push(int val,stack_item** ptr)
{
    stack_item* new_item = (stack_item*)malloc(sizeof(new_item));
    new_item->value = val;
    new_item->next = *ptr;
    *ptr=new_item;
    printf(" %d added to the stack.\n",val);
}


int Pop(stack_item** ptr)
{
    if((*ptr)==NULL)
    {
      printf("\n****ERROR: EMPTY STACK***\n\n");
      return 1;
    }

    int val;
    stack_item* old_ptr;
    old_ptr = *ptr;
    val=(*ptr)->value;
    *ptr = (*ptr)->next;
    free(old_ptr);

printf("%d was taken from the stack.\n",val);
return val;
}









int main()
{
    int val;
    char input[30];
    stack_item* new_stack= NULL;
    while(scanf("%s",input)>0)
    {
        if(strcmp(input,"Push")==0)
        {
            scanf("%d",&val);
            Push(val,&new_stack);
            continue;
        }

        if(strcmp(input,"Pop")==0)
        {
            Pop(&new_stack);
            continue;
        }
        if(strcmp(input,"EXIT")==0)
        {
            return 0;
        }
            printf("\n***ERROR: INVALID COMMAND***\n\n");
    }
    return 0;
}
