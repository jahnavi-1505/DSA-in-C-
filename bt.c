#include<stdio.h>
#iinclude<stdlib.h>
#include<string.h>
 struct node{
    int data;
    struct node* left;
    struct node* right;
 };

 struct node* newNode(int data)
 {
     struct node* node=(struct node*)malloc(sizeof(struct node));
     node->data=data;
     node->left=NULL;
     node->right=NULL;
     return node;
 }
 struct node* root=NULL;
 struct node* insert(int item,struct node* r)
 {
    struct node* temp=newNode(item);
    if(r==NULL){
        r=temp;
        return r;
    }
    else{
        char direction[20];
        printf("enter direction in uppercase:");
        scanf("%s",direction);
        struct node* current;
        struct node* prec;
        prev=NULL;
        current=r;
        int i;
        for(i=0;i<strlen(direction)&&current!=NULL;i++)
    }
 }

