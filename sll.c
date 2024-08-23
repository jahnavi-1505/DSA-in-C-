#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;

// Function to insert an element before another element in the existing list
void insertBeforeElement(int data, int element) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;

  NODE *temp = head;
  NODE *prev = NULL;
  while (temp != NULL && temp->data != element) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Element not found.\n");
  } else {
    newNode->next = temp;
    if (prev == NULL) {
      head = newNode;
    } else {
      prev->next = newNode;
    }
  }
}

// Function to insert an element after another element in the existing list
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
  }
}

// Function to delete a given element from the list
void deleteElement(int data) {
  NODE *temp = head;
  NODE *prev = NULL;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Element not found.\n");
  } else {
    if (prev == NULL) {
      head = head->next;
    } else {
      prev->next = temp->next;
    }
    free(temp);
  }
}

// Function to traverse the list
void traverseList() {
  NODE *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to reverse the list
void reverseList() {
  NODE *prev = NULL;
  NODE *current = head;
  NODE *next;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
}

// Function to sort the list
void sortList() {
  NODE *temp1 = head;
  NODE *temp2;
  int temp;

  while (temp1 != NULL) {
    temp2 = temp1->next;
    while (temp2 != NULL) {
      if (temp1->data > temp2->data) {
        temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
}

// Function to delete every alternate node in the list
void deleteAlternateNodes() {
  NODE *temp1 = head;
  NODE *temp2;

  while (temp1 != NULL && temp1->next != NULL) {
    temp2 = temp1->next;
    free(temp2);
    temp1->next = temp2->next;
    temp1 = temp1->next;
  }
}

// Function to insert an element in a sorted list such that the order is maintained
void insertElementInSortedList(int data) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;

  NODE *temp = head;
  NODE *prev = NULL;
  while (temp != NULL && temp->data < data) {
    prev = temp;
    temp = temp->next;
  }

  newNode->next = temp;
  if (prev == NULL) {
    head = newNode;
  } else {
    prev->next = newNode;
  }
}
