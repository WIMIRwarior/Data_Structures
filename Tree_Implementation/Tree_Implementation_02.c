#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

//ADDITIONAL TYPES:
typedef struct tree_element
{
  int value;
  struct tree_element* LEFT;
  struct tree_element* RIGHT;
  struct tree_element* ROOT;
} tree_element;


//GLOBAL VARIABLES:
int number_of_tree_elements = 0;
int ERROR_CODE = 12345678;
int OFFSET=6,WIDTH=5,number_of_display_rows=20,number_of_display_colums=255;
char tree_display[20][255];

tree_element* tree_root;
tree_element *SELECTED_TREE_ELEMENT = NULL;



//FUNCTIONS DECLARATIONS:
int is_it_int();

void show_tree_element (tree_element* tree_element_selected);

int add_tree_element (int L_or_R, tree_element** local_root, int *number_of_tree_elements);

void show_tree(tree_element* root);

int print_tree_into_display(tree_element* current_tree_node,int is_Left, int offset,int depth, char display[number_of_display_rows][number_of_display_colums]);

void move_throught_the_tree(tree_element** tree_element_selected,int* number_of_tree_elements);

void create_tree();

void remove_node(tree_element* tree_element_selected,int depth);

//===============MAIN===================================================================================================
int
main ()
{

  create_tree();
  return 0;
}
//===============MAIN===================================================================================================

//FUNCTIONS BODIES:

void clear_input_buffer ()
{
    while ( getchar() != '\n' );
}

int is_it_int()
{
    char input_to_check[5];
    scanf("%s",input_to_check);
    int input_length=0;
    input_length=strlen(input_to_check);

    for(int i=1;i<input_length;i++)
    {
        if(input_to_check[0]=='0'&&input_length>1)
        {
            printf("\n***VALUE IS NOT THE INTEGER***\n");
            sleep(2);
            return ERROR_CODE;
        }

        else if(input_to_check[i]>='0'&&input_to_check[i]<='9')
        {
            continue;
        }
        else
        {
            printf("\n***VALUE IS NOT THE INTEGER***\n");
            sleep(2);
            return ERROR_CODE;
        }
    }

    return atoi(input_to_check);
}

void show_tree_element (tree_element* tree_element_selected)
{   //system("clear");
    system("cls");

  printf("\nSELECTED NODE\n");
  if(tree_element_selected->ROOT)
  {
  printf ("\nROOT VALUE: %d\n", tree_element_selected->ROOT->value);
  }
  if(!tree_element_selected->ROOT)
  {
  printf("ROOT VALUE: NULL - It is the main root of the tree\n");
  }

  printf("VALUE:      %d\n",tree_element_selected->value);

  if(tree_element_selected->LEFT)
  {
    printf("CHILDREN: Left: %d",tree_element_selected->LEFT->value);
  }
  if(!tree_element_selected->LEFT)
  {
      printf("CHILDREN: Left: NULL");
  }
  if(tree_element_selected->RIGHT!=NULL)
  {
    printf("    Right: %d\n",tree_element_selected->RIGHT->value);
  }
  if(tree_element_selected->RIGHT==NULL)
  {
      printf("  Right: NULL\n");
  }
}



int add_tree_element (int L_or_R, tree_element** local_root, int *number_of_tree_elements)
{

    system("cls");

    int val=0;


    printf("Type value of the new node.\n:");

    val = is_it_int();

    if(val==ERROR_CODE)
    {
        printf("\n***ERROR: INVALID INPUT***\n");
        sleep(2);
        return 1;
    }

    if(val>999)
    {
        printf("\n***ERROR: VALUE TOO HIGH***\n");
        sleep(2);
        return 1;
    }

  tree_element* new_tree_element =(tree_element*) malloc (sizeof (tree_element));
  new_tree_element->value = val;
  new_tree_element->LEFT = NULL;
  new_tree_element->RIGHT = NULL;



  if (*number_of_tree_elements == 0)
	{
	  printf ("Root was added\n");
	  new_tree_element->ROOT = NULL;
	}
  else
	{
	  if (L_or_R == 0)
		{
		  (*local_root)->LEFT = new_tree_element;
		  new_tree_element->ROOT = (*local_root);
		  printf ("Left node added.\n");
		}
	  else
		{
		  (*local_root)->RIGHT = new_tree_element;
		  new_tree_element->ROOT = (*local_root);
		  printf ("Right node added.\n");
		}
	}

  *local_root = new_tree_element;
  (*number_of_tree_elements)++;

  sleep(1);
  clear_input_buffer();
  return 0;
}


void show_tree(tree_element* root)
{
    for(int i=0;i<number_of_display_rows;i++)
    {
        sprintf(tree_display[i],"%80s"," ");
    }

    print_tree_into_display(root,0,0,0,tree_display);

    for(int i=0;i<number_of_display_rows;i++)
    {
        printf("%s\n",tree_display[i]);
    }

}


int print_tree_into_display(tree_element* current_tree_node,int is_Left, int offset,int depth, char display[number_of_display_rows][number_of_display_colums])
{
    if(!current_tree_node)
    {
        return 0;
    }

    int L_offset=0, R_offset=0;
    char node_value_in_display_format[WIDTH];

    if(current_tree_node==SELECTED_TREE_ELEMENT)
    {
    sprintf(node_value_in_display_format,"[%.3d]",current_tree_node->value);
    }
    else
    {
        sprintf(node_value_in_display_format,"(%.3d)",current_tree_node->value);
    }

    L_offset = print_tree_into_display(current_tree_node->LEFT,1,offset,depth+1,display);
    R_offset = print_tree_into_display(current_tree_node->RIGHT,0,L_offset+offset+WIDTH,depth+1,display);

   for(int i=0;i<WIDTH;i++)
    {
        display[depth][L_offset+offset+i]=node_value_in_display_format[i];
    }


    if(depth&&is_Left)
    {
        for(int i=0;i<R_offset+WIDTH;i++)
        {
            display[depth-1][offset+L_offset+i+WIDTH/2]='-';
        }
        display[depth-1][offset+L_offset+WIDTH/2]='+';
    }

    if(depth&&!is_Left)
    {
        for(int i=0;i<L_offset+WIDTH/2;i++)
        {
            display[depth-1][offset+i]='-';
        }
        display[depth-1][offset+L_offset+WIDTH/2]='+';
    }

return WIDTH+L_offset+R_offset;

}


void move_throught_the_tree(tree_element** tree_element_selected,int* number_of_tree_elements)
{

if(!(*tree_element_selected))
{
    printf("\nMove through tree:   Cos nie tak z drzewem\n");
    sleep(3);
    return 1;
}


 for (int i = 0; i < 20; i++)
        {
            sprintf(tree_display[i], "%80s", " ");
        }


    int choose=0,go_out=1,new_value=0;

    while(go_out)
    {
        show_tree_element(*tree_element_selected);
        show_tree(tree_root);
        printf("\nWhere want you go or what you want to do?\n0-to root ,1-to left branch,2-to right branch,3-add/change left child, 4-add/change right child,\n5-remove branches of selected node,6-exit\n:");
        choose = is_it_int();
        if(choose==ERROR_CODE)
        {
            printf("\n***ERROR: INVALID INPUT***\n");
            sleep(2);
            continue;
        }

        switch (choose)
        {
            case 0:

            if((*tree_element_selected)->ROOT)
            {
             *tree_element_selected=(*tree_element_selected)->ROOT;
            }
            else
            {
                printf("\n***YOU'RE IN THE MAIN ROOT OF THE TREE!***\n");
                sleep(2);
            }
            break;

            case 1:
                if((*tree_element_selected)->LEFT)
                {
                 *tree_element_selected=(*tree_element_selected)->LEFT;
                }
                else
                {
                    printf("\n***THIS NODE HAS NO LEFT CHILD!***\n");
                    sleep(2);
                }

            break;

            case 2:
            if((*tree_element_selected)->RIGHT)
                {
                 *tree_element_selected=(*tree_element_selected)->RIGHT;
                }
                else
                {
                    printf("\n***THIS NODE HAS NO RIGHT CHILD!***\n");
                    sleep(2);
                }
            break;

            case 3:
            if((*tree_element_selected)->LEFT)
            {
                printf("The node already exist. Do You want to change it's value?\n1-YES 2-NO\n:");

                choose = is_it_int();
                if(choose==ERROR_CODE)
                {
                    printf("\n***ERROR: INVALID INPUT***\n");
                    sleep(2);
                    continue;
                }

                if(choose==1)
                {
                    printf("\nSet new value: ");

                    new_value = is_it_int();
                    if(new_value==ERROR_CODE)
                    {
                        printf("\n***ERROR: INVALID INPUT***\n");
                        sleep(2);
                        continue;
                    }
                    (*tree_element_selected)->LEFT->value=new_value;
                }
                else
                {
                    break;
                }
            }
            else
            {
                add_tree_element (0, tree_element_selected, &number_of_tree_elements);

            }
            break;

            case 4:
            if((*tree_element_selected)->RIGHT)
            {
                printf("The node already exist. Do You want to change it's value?\n1-YES 2-NO\n:");

                choose = is_it_int();
                if(choose==ERROR_CODE)
                {
                    printf("\n***ERROR: INVALID INPUT***\n");
                    sleep(2);
                    continue;
                }

                if(choose==1)
                {
                    printf("\nSet new value: ");

                    new_value = is_it_int();
                    if(new_value==ERROR_CODE)
                    {
                        printf("\n***ERROR: INVALID INPUT***\n");
                        sleep(2);
                        continue;
                    }
                    (*tree_element_selected)->RIGHT->value=new_value;
                }
                else
                {
                    break;
                }
            }
            else
            {
                add_tree_element (1, tree_element_selected, &number_of_tree_elements);
            }
            break;

            case 5:
              if((*tree_element_selected)->LEFT&&(*tree_element_selected)->RIGHT)
              {
                  printf("\nWhich branch do You want to remove?\n1)LEFT    2)RIGHT  3)BOTH\n");
                  choose = is_it_int();
                if(choose==ERROR_CODE)
                {
                    printf("\n***ERROR: INVALID INPUT***\n");
                    sleep(2);
                    return 1;
                }
                else
                {
                    switch(choose)
                    {
                        case 1:
                            remove_node((*tree_element_selected)->LEFT,0);
                            free((*tree_element_selected)->LEFT);
                            (*tree_element_selected)->LEFT=NULL;
                            break;

                        case 2:
                            remove_node((*tree_element_selected)->RIGHT,0);
                            free((*tree_element_selected)->RIGHT);
                            (*tree_element_selected)->RIGHT=NULL;
                            break;

                        case 3:
                            remove_node(*tree_element_selected,0);
                            break;

                        default:
                            printf("\n***ERROR: INVALID INPUT***\n");
                            sleep(2);
                    }
                }
              }
              else
              {
                remove_node(*tree_element_selected,0);
              }
              break;

            case 6:
            go_out=0;
            system("cls");
            printf("\n\nGOOD BYE :) \n\n");
            break;

            default:
            printf("\n****ERROR: WRONG COMMAND!****\n");
            sleep(2);

        }
    }
}

void create_tree()
    { int was_tree_create=1;
        while(was_tree_create)
        {
           if(!(add_tree_element(0,&tree_root,&number_of_tree_elements)))
           {
               sleep(2);
           SELECTED_TREE_ELEMENT = tree_root;
           move_throught_the_tree(&SELECTED_TREE_ELEMENT,&number_of_tree_elements);
           was_tree_create=0;
           }
           else
           {
               printf("\n***ERROR: CAN NOT CREATE TREE***\n");
               sleep(2);
           }
        }
    }

void remove_node(tree_element* tree_element_selected,int depth) // The possibility of choosing which side should be deleted has to be writen :)
    {
        if(tree_element_selected->RIGHT)
        {
            remove_node(tree_element_selected->RIGHT,1);
        }
        if(tree_element_selected->LEFT)
        {
            remove_node(tree_element_selected->LEFT,1);
        }
        if(depth>0)
            {
                free(tree_element_selected);
            }
            else
            {
                tree_element_selected->RIGHT=NULL;
                tree_element_selected->LEFT=NULL;
            }
        }

