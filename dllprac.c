#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

struct node* first=NULL;

void reverse(){
    struct node* cur=first;
    struct node* temp;
    while(cur!=NULL){
        temp=cur->left;
        cur->left=cur->right;
        cur->right=temp;
        cur=cur->left;
    }
    first=temp->left;

}

void display(){
    if(first==NULL)
    printf("empty list");
    struct node* curr;

    for(curr=first;curr!=NULL;curr=curr->right){
        printf("%d",curr->data);
        printf("\n");
    }
}

int main(){
    struct node* n1=(struct node*)malloc(sizeof(struct node));
    struct node* n2=(struct node*)malloc(sizeof(struct node));
    struct node* n3=(struct node*)malloc(sizeof(struct node));
    struct node* n4=(struct node*)malloc(sizeof(struct node));
    n1->data=10;
    n1->left=NULL;
    n1->right=n2;
    first=n1;
    n2->data=20;
    n2->left=first;
    n2->right=n3;
    n3->left=n2;
    n3->right=n4;
    n3->data=30;
    n4->data=40;
    n4->left=n3;
    n4->right=NULL;
    display();
    reverse();
    display();
}

