#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tree_item{

int value;
struct tree_item* root;
struct tree_item* left;
struct tree_item* right;

}tree_item;

tree_item* SELECTED_ITEM = NULL;
tree_item* MAIN_ROOT = NULL;


void Add_Item(int val,tree_item** tree,bool LR,int* number_of_items)  // At this point this function works properly.
{
    tree_item* new_tree_item = (tree_item*)malloc(sizeof(tree_item));

    new_tree_item->value = val;
    new_tree_item->left = NULL;
    new_tree_item->right=NULL;

    if(*number_of_items==0)
    {
       (*tree) = new_tree_item;
        (*tree)->left=NULL;
        (*tree)->right=NULL;
        (*tree)->root=NULL;
        MAIN_ROOT=new_tree_item;
    }
    else
    {
        new_tree_item->root=(*tree);
        if(LR)
        {
            (*tree)->left=new_tree_item;
        }
        else
        {
            (*tree)->right=new_tree_item;
        }
    }
    (*number_of_items)++;
    printf("New item with value: %d was added to the tree\nCurrent number of tree elements: %d\n",val,*number_of_items);
    SELECTED_ITEM = new_tree_item;

}

void Show_Tree(tree_item* item)  //WIP - nodes displaying in order of it's creation. Nodes should to be displayed in tree order.
{
    printf("%d ",item->value);
    if(item->left!=NULL)
    {
        Show_Tree(item->left);
    }
    if(item->right!=NULL)
    {
        Show_Tree(item->right);
    }
}


#define LEFT false
#define RIGHT true




int main()
{
    int number_of_items=0;
    Add_Item(7,&SELECTED_ITEM,LEFT,&number_of_items);
    Add_Item(9,&SELECTED_ITEM,RIGHT,&number_of_items);
    Add_Item(10,&SELECTED_ITEM,LEFT,&number_of_items);
    Add_Item(11,&SELECTED_ITEM,LEFT,&number_of_items);
    Add_Item(12,&SELECTED_ITEM,RIGHT,&number_of_items);
    Add_Item(13,&SELECTED_ITEM,RIGHT,&number_of_items);


    Show_Tree(MAIN_ROOT);


    return 0;
}
