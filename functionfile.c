#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include"headerfile.h"
//  to create a new BST node 
struct tree *newNode(char *item,char* itline) 
{ 
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree)); 
    strcpy(temp->key,item);                                                            //assigning item to temp->key
    strcpy(temp->page,itline);
    temp->left = temp->right = NULL; 
    return temp; 
} 

// To do inorder traversal of BST
// inorder traversal of BST prints data in alphabetically sorted manner
void display(struct tree *root) 
{ 
    if (root != NULL) 
    { 
        display(root->left); 
        printf("%-20s", root->key);                  //Printing the major terms(insex terms) 
        printf("%-20s \n",root->page);                 
        display(root->right); 
    } 
} 
// Insert nodes into the BST
struct tree* insert(struct tree* node, char* key, char* itline) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key,itline); 

    /* Otherwise, recur down the tree */
    if(strcmp(key,node->key)<0)
        node->left = insert(node->left, key, itline); 
    else if (strcmp(key,node->key)>0) 
        node->right = insert(node->right, key,itline); 

    return node; 
} 

//Search for a specific index/major term
void search(struct tree* root, char* key)
{
    while(root!=NULL)
    {
        /* if key is found as root node, print it */
        if(strcmp(root->key,key)==0)
            {
                printf("\nEntered term available in lines %s\n\n",root->page);
                return;
            }
        /* if key not found, recursive call to the function */
        else if(strcmp(root->key,key)<0)
            return(search(root->right,key));
        else if(strcmp(root->key,key)>0)
            return(search(root->left,key));
    }
    printf("\nEnterted term not available in index\n\n");
}