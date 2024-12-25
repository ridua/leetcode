#include <stdio.h>

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}


int removeElement(int* a, int n, int key) {

  int i = 0; // traverse the array
  int k = 0; // reduced elemetn

  for (i = 0; i <n; i++) {
      if (a[i] != key) {
          a[k] = a[i];
          k++;
      }
  }
  return k;
}


int main()
{
  // int arr[] = {3,2,2,3};
  // int arr[] = {3,3};
  // int arr[] = {3};
  int arr[] = {32,2};

  int rv = removeElement(arr, sizeof(arr)/sizeof(arr[0]), 3);

  printf("\n %d\n", rv);
  return 0;
}
