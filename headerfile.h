#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{ 
    char key[35];                            //For Major Terms
    char page[50];                          //To display pages
    struct tree *left;
    struct tree *right; 
}; 
struct tree *newNode(char *item,char* itpage);      //  to create a new BST node 
void display(struct tree *root);                    // To do inorder traversal of BST
struct tree* insert(struct tree* node, char* key, char* itpage);        // Insert nodes into the BST
void search(struct tree* root, char* key);              //Search for a specific index/major term