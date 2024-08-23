#include <stdio.h>

void selection_sort(int arr[], int low, int high) {
  if (low >= high) {
    return;
  }

  int min_index = low;
  for (int i = low + 1; i <= high; i++) {
    if (arr[i] < arr[min_index]) {
      min_index = i;
    }
  }

  int temp = arr[low];
  arr[low] = arr[min_index];
  arr[min_index] = temp;

  selection_sort(arr, low + 1, high);
}

int main() {
  int size,i;
    printf("enter no. of elements:");
    scanf("%d",&size);  int arr[size];
  printf("enter elements:");
  for(i=0;i<size;i++)
  {
      scanf("%d",&arr[i]);
  }


  selection_sort(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

