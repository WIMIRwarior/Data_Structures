#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

//Global variables
int number_of_tree_elements = 0;
int OFFSET=6;
char tree_table[20][255];

typedef struct tree_element
{
  int value;
  struct tree_element* LEFT;
  struct tree_element* RIGHT;
  struct tree_element* ROOT;
} tree_element;

tree_element* tree_root;
tree_element *SELECTED_TREE_ELEMENT = NULL;


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
    printf("    Right: %d",tree_element_selected->RIGHT->value);
  }
  if(tree_element_selected->RIGHT==NULL)
  {
      printf("  Right: NULL\n");
  }
}



void add_tree_element (int L_or_R, tree_element ** local_root, int *number_of_tree_elements)
{
    //system("clear");
        system("cls");

    int val=0;


    printf("Type value of the new node.\n:");
    scanf("%d",&val);

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
		  printf ("dodalem z lewej\n");
		}
	  else
		{
		  (*local_root)->RIGHT = new_tree_element;
		  new_tree_element->ROOT = (*local_root);
		  printf ("dodalem z prawej\n");
		}
	}

  *local_root = new_tree_element;
  (*number_of_tree_elements)++;
  sleep(1);
 // printf ("%d ", *number_of_tree_elements);
}


int print_tree(tree_element* current_node,int depth, int is_Left, int offset,char display[20][255])
    {
        char data_to_print[10];
        int width=5,Left_offset=0,Right_offset=0;

        sprintf(data_to_print,"(%3d)",current_node->value);

        Left_offset=print_tree(current_node->LEFT,depth+1,1,offset,display);
        Right_offset=print_tree(current_node->RIGHT,depth+1,0,offset,display);

        if(depth&&is_Left)
        {

        }

        else if(depth&&!is_Left)
        {

        }
        else
        {

        }

        return Left_offset+Right_offset+width;

    }







void move_throught_the_tree(tree_element** tree_element_selected,int* number_of_tree_elements)
{

    show_tree_element(*tree_element_selected);
    int choose=0,go_out=1,new_value=0;

    while(go_out)
    {
        printf("\nWhere want you go or what you want to do?\n0-to root ,1-to left branch,2-to right branch,3-add/change left child, 4-add/change right child,\n5-remove selected node,6-exit\n:");
        scanf("%d",&choose);
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
                    printf("\n***THIS NODE HAS NO LEFT RIGHT!***\n");
                    sleep(2);
                }
            break;

            case 3:
            if((*tree_element_selected)->LEFT)
            {
                printf("The node already exist. Do You want to change it's value?\n1-YES 2-NO\n:");
                scanf("%d",&choose);
                if(choose==1)
                {
                    printf("\nSet new value: ");
                    scanf("%d",&new_value);
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
                scanf("%d",&choose);
                if(choose==1)
                {
                    printf("\nSet new value: ");
                    scanf("%d",&new_value);
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
            remove_node(*tree_element_selected,0);
            break;

            case 6:
            go_out=0;
            break;

            default:
            printf("\n****ERROR: WRONG COMMAND!****\n");
            sleep(2);

        }
        if(go_out)
        {
            show_tree_element(*tree_element_selected);
        }
    }

}

void create_tree()
    {
       add_tree_element(0,&tree_root,&number_of_tree_elements);
       move_throught_the_tree(&tree_root,&number_of_tree_elements);
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


int
main ()
{
   for(int i=0;i<20;i++)
        {
            sprintf(tree_table[i],"%255s"," ");
        }

  create_tree();
  return 0;
}
