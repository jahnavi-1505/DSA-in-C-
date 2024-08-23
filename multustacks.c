#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10
#define MAX_SIZE 100

int *arr;
int top[MAX_STACKS];
int bottom[MAX_STACKS];
int stack_size;

void initializeStacks(int numStacks, int arraySize) {
    stack_size = arraySize / numStacks;

    arr = malloc(sizeof(int) * arraySize); // Allocate memory for the array

    for (int i = 0; i < numStacks; i++) {
        top[i] = i * stack_size - 1;
        bottom[i] = i * stack_size;
    }
}

void push(int stackNum, int value) {
    if (top[stackNum] + 1 == bottom[stackNum + 1]) {
        printf("Stack %d is full\n", stackNum);
        return;
    }

    top[stackNum]++;
    arr[top[stackNum]] = value;
}

int pop(int stackNum) {
    if (top[stackNum] == bottom[stackNum]) {
        printf("Stack %d is empty\n", stackNum);
        return -1; // Return a sentinel value to indicate error
    }

    int value = arr[top[stackNum]];
    top[stackNum]--;
    return value;
}

void display(int stackNum) {
    if (top[stackNum] == bottom[stackNum]) {
        printf("Stack %d is empty\n", stackNum);
        return;
    }

    printf("Stack %d contents: ", stackNum);
    for (int i = top[stackNum]; i >= bottom[stackNum]; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numStacks, arraySize;
    printf("Enter the number of stacks: ");
    scanf("%d", &numStacks);
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    initializeStacks(numStacks, arraySize);

    int stackNum, value;

    while (1) {
        printf("\nEnter operation: 1-Push, 2-Pop, 3-Display, 4-Exit: ");
        scanf("%d", &value);

        switch (value) {
            case 1:
                printf("Enter stack number and value to push: ");
                scanf("%d %d", &stackNum, &value);
                push(stackNum, value);
                break;

            case 2:
                printf("Enter stack number to pop: ");
                scanf("%d", &stackNum);
                int popped = pop(stackNum);
                if (popped != -1) {
                    printf("Popped value: %d\n", popped);
                }
                break;

            case 3:
                printf("Enter stack number to display: ");
                scanf("%d", &stackNum);
                display(stackNum);
                break;

            case 4:
                free(arr); // Free the allocated memory
                return 0; // Return instead of exit

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
