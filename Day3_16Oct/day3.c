// contains functions to construct a parse tree and print the infix expression.
// author : Rashi Jain, 11/10/19

// prints the infix expression via inorder traversal.
// root : Pointer to root of the binary tree. (dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;
//   	struct node *left;
//		struct node *right;
// }node;
// return : void
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modifiedDay1.h"
void inorder(node *root)
{
    if(root->right!=NULL) printf("(");
    if(root->left!=NULL) inorder(root->left);
    printf("%c", root->ch);
    if(root->right!=NULL) inorder(root->right);
    if(root->right!=NULL) printf(")");
}
// constructs the binary tree given a postfix expression.
// post_exp : character array containing postfix expression.
// return : (node *) dataype - pointer to the root of the binary tree.
node* parseTree(char post_exp[])
{
    int stackPointer = -1, max=100;
    struct node * stack[max];
    for(int i=0; i<strlen(post_exp); i++)
    {
        char temp=post_exp[i];
        if((temp!='~')&&(temp!='V')&&(temp!='^')&&(temp!='>'))
        {
            struct node* pp=(struct node *)malloc(sizeof(struct node));
            pp->ch=temp;
            pp->left=pp->right=NULL;
            push(stack, max, &stackPointer, pp );
        }
        else if(temp!='~')
        {
            struct node* pp=(struct node *)malloc(sizeof(struct node));
            pp->ch=temp;
            pp->left=pp->right=NULL;
            struct node* right =top(stack, max, stackPointer);
            pop(stack, max, &stackPointer);
            struct node* left =top(stack, max, stackPointer);
            pop(stack, max, &stackPointer);
            pp->left=left;
            pp->right=right;
            push(stack, max, &stackPointer, pp );
        }
        else
        {
            struct node* pp=(struct node *)malloc(sizeof(struct node));
            pp->ch=temp;
            pp->left=pp->right=NULL;
            struct node* child =top(stack, max, stackPointer);
            pop(stack, max, &stackPointer);
            pp->right=child;
            push(stack, max, &stackPointer, pp );
        }
    }
    return top(stack, max, stackPointer);
}