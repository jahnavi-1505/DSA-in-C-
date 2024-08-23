#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;

NODE *head = NULL;
NODE *tail = NULL;

// Function to insert an element at the rear end of the list
void insertAtRear(int data) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
    newNode->prev = NULL;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

// Function to delete an element from the rear end of the list
void deleteAtRear() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (head == tail) {
    head = NULL;
    tail = NULL;
    free(head);
  } else {
    NODE *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
  }
}

// Function to insert an element at a given position of the list
void insertAtGivenPosition(int data, int position) {
  if (position < 1) {
    printf("Invalid position.\n");
    return;
  }

  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;

  if (position == 1) {
    newNode->next = head;
    head = newNode;
    head->prev = NULL;
  } else {
    NODE *temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
  }
}

// Function to delete an element from a given position of the list
void deleteAtGivenPosition(int position) {
  if (position < 1) {
    printf("Invalid position.\n");
    return;
  }

  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (position == 1) {
    head = head->next;
    head->prev = NULL;
  } else {
    NODE *temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    NODE *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    free(nodeToDelete);
  }
}

// Function to insert an element after another element
void insertAfterElement(int data, int element) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;

  NODE *temp = head;
  while (temp != NULL && temp->data != element) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Element not found.\n");
  } else {
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
  }
}

// Function to insert an element before another element
void insertBeforeElement(int data, int element) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;

  NODE *temp = head;
  while (temp
