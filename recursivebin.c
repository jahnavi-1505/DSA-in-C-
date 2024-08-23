#include <stdio.h>

int binary_search(int arr[], int low, int high, int key) {
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;

  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] < key) {
    return binary_search(arr, mid + 1, high, key);
  } else {
    return binary_search(arr, low, mid - 1, key);
  }
}

int main() {
    int n,i;
    printf("enter no. of elements:");
    scanf("%d",&n);  int arr[n];
  printf("enter elements:");
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }


  int key;
  printf("enter element to be found:");
  scanf("%d",&key);

  int index = binary_search(arr, 0, sizeof(arr) / sizeof(int) - 1, key);

  if (index == -1) {
    printf("Element not found");
  } else {
    printf("Element found at index: %d", index);
  }

  return 0;
}

